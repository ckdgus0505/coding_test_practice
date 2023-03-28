#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
int N;
int** arr;

void init() {
  cin >> N;
  arr = (int**) malloc (sizeof(int*)*N);
  for (int i = 0; i < N; i++) {
    arr[i] = (int*) malloc(sizeof(int)*N);
    for (int j = 0; j < N; j++) {
      cin >> arr[i][j] ;
    }
  }
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  init();
  int result = 987654321;
  vector<int> grp;
  for (int i = 0; i < N/2; i++) {
    grp.push_back(0);
  }
    for (int i = 0; i < N/2; i++) {
    grp.push_back(1);
  }

  do{
    int score_1 = 0;
    int score_2 = 0;
    for (int i = 0; i < N; i++) {
      for (int j = i+1; j < N; j++)
        if (grp[i] == grp[j]) {
          if (grp[i] == 0) score_1 += arr[i][j] + arr[j][i];
          else if (grp[i] == 1) score_2 += arr[i][j] + arr[j][i];
        }
    }

    result = min(result, abs(score_1-score_2));
    
  }while (next_permutation(grp.begin(), grp.end()));
  cout << result << endl;

  return 0;
}