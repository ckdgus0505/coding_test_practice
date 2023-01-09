#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int N;
vector<pair<int, int>> adj[100000];

long long int dijk(int start) {
  vector<int> visited(N, 987654321);
  priority_queue<pair<int, int>> pq; // first: score, second: location
  pq.push(make_pair(0, start));
  visited[start] = 0;
  while(!pq.empty()) {
    int from = pq.top().second;
    int dist = pq.top().first;
    pq.pop();
    if (visited[from] < dist ) continue;
    for (int i = 0; i < adj[from].size(); i++) {
      int to = adj[from][i].first;
      int score = adj[from][i].second;
      if (visited[to] > dist + score) {
        visited[to] = dist + score;
        pq.push(make_pair(dist+score, to));
      }

    }
  }
  long long int ret = 0;
  for (int i = 0; i < visited.size(); i++) {
    ret += visited[i];
  }
  return ret;
}
int main(int argc, char** argv)
{
  cin >> N;
  for (int i = 0; i < N-1; i++) {
    int a,b,c;
    cin >> a >> b >> c;
    adj[a-1].push_back(make_pair(b-1, c));
    adj[b-1].push_back(make_pair(a-1, c));
  }
  for (int i = 0; i < N; i++) {
    cout << dijk(i) << endl;
  }
  
	return 0;
}