#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdio>

using namespace std;
int N;
vector<int> obs; // 장애물 수 담는 배열
vector<vector<int>> map;
queue<pair<int, int>> q;
int move_x[] = {1, -1, 0, 0};
int move_y[] = {0, 0, 1, -1};

int bfs(int x, int y) {
  int ret = 1;
  while(!q.empty()) {
    int pos_x = q.front().first;
    int pos_y = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int next_x = pos_x + move_x[i];
      int next_y = pos_y + move_y[i];
      if (0 <= next_x && next_x < N && 0 <= next_y && next_y < N &&
        map[next_x][next_y]==-1) {
        q.push(make_pair(next_x, next_y));
        map[next_x][next_y] = obs.size()+1;
        ret += 1;
      }
    }
  }
  return ret;
}


int main(int argc, char** argv) {
  cin >> N;
  map = vector<vector<int>>(N, vector<int>(N, 0));
  for (int i = 0; i < N; i++) {
    int tmp;
    for (int j = 0; j < N; j++) {
      scanf("%1d", &tmp);
      map[i][j] = -1*tmp;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0;  j < N; j++) {
      if (map[i][j] == -1) {

        map[i][j] = obs.size()+1;
        q.push(make_pair(i,j));
        obs.push_back(bfs(i, j));
      }
    }
  }
  
  sort(obs.begin(), obs.end());
  cout << obs.size() << endl;
  for (int i = 0; i < obs.size(); i++) {
    cout << obs[i] << endl;
  }
	return 0;
}