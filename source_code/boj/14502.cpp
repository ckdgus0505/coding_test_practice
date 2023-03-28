#include <iostream>
#include <cstdlib>
#include <queue>
#include <vector>
using namespace std;
int N ,M;
int num_zeros = 0;
int** arr;
int moves[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
vector<pair<int, int>> virus;

void init() {
  cin >> N >> M;
  arr = (int**) malloc (sizeof(int*) * N);
  for (int i = 0; i < N; i++) {
    arr[i] = (int*) malloc(sizeof(int)*M);
    for (int j = 0; j < M; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 2) virus.push_back(make_pair(i, j));
      if (arr[i][j] == 0) num_zeros++;
    }
  }
}

int spread_virus() {
  int ret = 0;
  queue<pair<int, int>> q;
  vector<vector<bool>> visited(N, vector<bool>(M,0));
  for (int i = 0; i < virus.size(); i++) {
    q.push(virus[i]);
    visited[virus[i].first][virus[i].second] = true;
  }

  while(!q.empty()) {
    pair<int,int> now = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int next_n = now.first+moves[i][0];
      int next_m = now.second+moves[i][1];
      if (0 <= next_n && next_n < N && 0 <= next_m && next_m < M) {
        if (arr[next_n][next_m] == 0 && !visited[next_n][next_m]) {
          ret++;
          visited[next_n][next_m] = true;
          q.push(make_pair(next_n, next_m));
        }
      }
    }
  }
  return ret;
}

void draw_map() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << arr[i][j];
    }
  cout << endl;
  }
}

int dfs(int wall_cnt) {
  int ret = -1;
  if (wall_cnt == 3) {
    ret = num_zeros - 3 - spread_virus();
    return ret;
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (arr[i][j] == 0) {
        arr[i][j] = 1;
        ret = max(ret, dfs(wall_cnt+1));
        arr[i][j] = 0;
      }
    }
  }
  return ret;
}




int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  init();
  cout << dfs(0) << endl;
  
}