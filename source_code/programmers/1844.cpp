#include <iostream>
#include <vector>
#include <queue>
/* 풀이 아이디어:
  최솟값 : BFS --> queue를 만들어서 해결

  시행착오 : 효율성 테스트에서 틀림
  --> DFS와 착각하여 queue에서 뺄때 기존의 state를 복원해야 한다고 생각했음
  --> maps말고 visit함수를 따로 만들어서 하니 시간 초과가 생겼었는데, 이는 참조해야        할 부분을 최소화 해야 하는 것 같음
*/
using namespace std;
int N = 100;
int M = 100;
int move_x[4] = {1, -1, 0, 0};
int move_y[4] = {0, 0, 1, -1};
typedef pair<int, int> pos;
priority_queue<pair<int, pos>> pq;

int bfs(vector<vector<int> >& maps) {
  int ret = 1;
  pq.push(make_pair(-1, make_pair(0, 0)));
  maps[0][0] = 0;
  while (!pq.empty()) {
    int now = pq.top().first;
    int pos_x = pq.top().second.first;
    int pos_y = pq.top().second.second;
    pq.pop();
    
    if (pos_x == N-1 && pos_y == M-1) {
      ret = now;
      break;
    }

    for (int i = 0; i < 4; i++) {
      int next_x = pos_x + move_x[i];
      int next_y = pos_y + move_y[i];
      if (0 <= next_x && next_x < N && 0 <= next_y && next_y < M &&
        maps[next_x][next_y]==1) {
      pq.push(make_pair(now - 1, make_pair(next_x, next_y)));
      maps[next_x][next_y]=0;
      }
    }
  }
  return ret* -1;
}

int solution(vector<vector<int> > maps)
{  
  int answer = 0;
  N = maps.size();
  M = maps[0].size();
  answer = bfs(maps);
  return answer;
}
int main(void) {
  vector<vector<int> > maps = {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}};
  cout << solution(maps) << endl;
  return 0;
}