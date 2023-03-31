#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
int S, E;
int v1, v2;
// pair 의 first는 거리 second 는 위치
priority_queue<pair<int,int>> pq;
vector<pair<int, int>> adj[800];
void init() {
  cin >> S >> E;
  for (int i = 0; i < E; i++) {
    int tmp1, tmp2,tmp3;
    cin >> tmp1 >> tmp2 >> tmp3;

    adj[tmp1-1].push_back(make_pair(tmp3, tmp2-1));
    adj[tmp2-1].push_back(make_pair(tmp3, tmp1-1));
  }
  cin >> v1 >> v2;
}

int dijkstra(int start, int end){
  int score[800];
  for (int i = 0; i < 800; i++) {score[i] = INF;}
  pq.push(make_pair(0,start));
  score[start] = 0;
  while(!pq.empty()) {
    pair<int, int> tmp = pq.top();
    pq.pop();
    if (score[tmp.second] < -tmp.first) continue;
    for (int i = 0; i < adj[tmp.second].size(); i++) {
      if (score[adj[tmp.second][i].second] > score[tmp.second] + adj[tmp.second][i].first) {
        score[adj[tmp.second][i].second] = score[tmp.second] + adj[tmp.second][i].first;
        pq.push(make_pair(-adj[tmp.second][i].first, adj[tmp.second][i].second));
      }
    }
  }
  if (score[end] == INF) return -1;
  else return score[end];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init();

  int sv1 = dijkstra(0, v1-1);
  int sv2 = dijkstra(0, v2-1);
  int v1e = dijkstra(v1-1, S-1);
  int v2e = dijkstra(v2-1, S-1);
  int v1v2 = dijkstra(v1-1, v2-1);
  if (v1v2==-1 || ((sv1==-1 || v2e==-1) && (sv2==-1 || v1e==-1)) ) cout << -1 << endl;
  else cout << min(sv1+v2e, sv2+v1e) + v1v2 << endl;
  return 0;
}