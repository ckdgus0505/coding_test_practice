#include<iostream>

using namespace std;
int N;
int A[3001];
int cache[3001];

int dfs(int cur) { // cur을 밟고 이후로 갈 수 있는 최대 갯수를 반환
  int M = 0;
  if (cache[cur]!=0) return cache[cur];
  for (int i = cur+1; i <= N; i++) {
    if (A[i] > A[cur]) {
      M = max(M, dfs(i)+1);
    }
  }
  cache[cur]=M;
  return M;
}
int main(int argc, char** argv)
{
  cin >> N;
  for(int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  
  cout << dfs(0) << endl;
	return 0;
}