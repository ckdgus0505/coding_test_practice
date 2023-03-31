#include <iostream>
#include <vector>

// DP를 이용한 LIS (Least increasing Subsequences)

using namespace std;
vector<int> row;
int cache[202];
int N;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N;
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    row.push_back(tmp);
  }
  
  for (int k = 0; k < N; k++) {
    cache[k]=1;
    for (int i = 0; i < k; i++) {
      if (row[i] < row[k]) {
        cache[k] = max(cache[k], cache[i]+1);
      }
    }
  }
  for (int i = 0; i < N; i++) cout << cache[i] << ' ' ;

  cout << cache[N]<< endl;
  
  return 0;
}