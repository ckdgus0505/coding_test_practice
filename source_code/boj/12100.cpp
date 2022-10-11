#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
/* 풀이 아이디어:
  depth가 5 이므로 최대 4^5=1024의 경우의 수
  전수조사 가능, --> dfs로 풀이
  dfs + 시뮬레이션으로 풀면 될듯
  함수1: 이동하여 합치는 함수
  함수2: max값 확인하는 함수
  함수3: dfs
*/
vector<vector<int>> arr;
int n;
int find_max(vector<vector<int>>&);
void print_arr(vector<vector<int>>& map);
vector<vector<int>> move(vector<vector<int>>, int);
int dfs(vector<vector<int>>, int);




vector<vector<int>> move(vector<vector<int>> map, int direction) {
  // direction 0: up 1: left 2: down 3: right
  switch(direction) {
    case 0:
      for (int i = 0; i < n; i++) {
        queue<int> q1;
        queue<int> q2;
        for(int j = 0; j < n; j++) {
          if (map[j][i]!=0) q1.push(map[j][i]);
        }
        while(!q1.empty()){
          int tmp = q1.front();
          q1.pop();
          if (!q1.empty() && q1.front() == tmp) {
            tmp += q1.front();
            q1.pop();
          }
          q2.push(tmp);
        }
        for (int j = 0; j < n; j++) {
          if (!q2.empty()) {
            map[j][i] = q2.front();
            q2.pop();
          } else map[j][i] = 0;
        }
      }
      break;
    case 1:
      for (int i = 0; i < n; i++) {
        queue<int> q1;
        queue<int> q2;
        for(int j = 0; j < n; j++) {
          if (map[i][j]!=0) q1.push(map[i][j]);
        }
        while(!q1.empty()){
          int tmp = q1.front();
          q1.pop();
          if (!q1.empty() && q1.front() == tmp) {
            tmp += q1.front();
            q1.pop();
          }
          q2.push(tmp);
        }
        for (int j = 0; j < n; j++) {
          if (!q2.empty()) {
            map[i][j] = q2.front();
            q2.pop();
          } else map[i][j] = 0;
        }
      }
      break;
    case 2:
      for (int i = 0; i < n; i++) {
        stack<int> s1;
        queue<int> q2;
        for(int j = 0; j < n; j++) {
          if (map[j][i]!=0) s1.push(map[j][i]);
        }
        while(!s1.empty()){
          int tmp = s1.top();
          s1.pop();
          if (!s1.empty() && s1.top() == tmp) {
            tmp += s1.top();
            s1.pop();
          }
          q2.push(tmp);
        }
        for (int j = n-1; j >= 0; j--) {
          if (!q2.empty()) {
            map[j][i] = q2.front();
            q2.pop();
          } else map[j][i] = 0;
        }
      }
      break;
    case 3:
      for (int i = 0; i < n; i++) {
        stack<int> s1;
        queue<int> q2;
        for(int j = 0; j < n; j++) {
          if (map[i][j]!=0) s1.push(map[i][j]);
        }
        while(!s1.empty()){
          int tmp = s1.top();
          s1.pop();
          if (!s1.empty() && s1.top() == tmp) {
            tmp += s1.top();
            s1.pop();
          }
          q2.push(tmp);
        }
        for (int j = n-1; j >= 0; j--) {
          if (!q2.empty()) {
            map[i][j] = q2.front();
            q2.pop();
          } else map[i][j] = 0;
        }
      }
      break;
  }
  // cout << "=====" << endl;
  // print_arr(map);
  return map;
  }

int dfs(vector<vector<int>> map, int depth) {
  int m = -1;
  int tmp;
  if (depth == 5) {
    return find_max(map);
  }

  for (int i = 0; i < 4; i++) {
    tmp = dfs(move(map, i), depth+1);
    if (tmp > m)
      m = tmp;
  }
  return m;
}

int find_max(vector<vector<int>>& map){
  int M = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (map[i][j] > M) M = map[i][j];
    }
  }
  return M;
}

void print_arr(vector<vector<int>>& map){
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << map[i][j] << ' ';
    }
    cout << endl;
  }
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  arr = vector<vector<int>>(n,vector<int>(n,0));
  int tmp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> tmp;
      arr[i][j] = tmp;
    }
  }
  cout << dfs(arr, 0) << endl;
  // move(move(move(move(move(arr, 1),0),1),2),1);
}