#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<pair<int, int>> arr[4];
int main(int argc, char** argv)
{
  int N;
  cin >> N;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < N; j++) {
      int tmp;
      cin >> tmp;
      arr[i].push_back(make_pair(tmp, j));
    }
  }
  for (int i = 0; i < N; i++) {
    int tmp = 0;
    for (int j = 0; j < 3; j++) {
      tmp += arr[j][i].first;
    }
    arr[3].push_back(make_pair(tmp, i));
  }

  
  for (int i = 0; i < 4; i++) {
    int count = 1;
    vector<int> ranks(N,0);
    sort(arr[i].begin(), arr[i].end(), greater<pair<int, int>>());
    int prev = 1001;
    int prev_count = 1;
    for (int j = 0; j < N; j++) {
      if (arr[i][j].first < prev) {
        ranks[arr[i][j].second] = count;
        prev_count = count;
      } else {
        ranks[arr[i][j].second] = prev_count;
      }
      prev = arr[i][j].first;
      count++;
    }
    for (int j = 0; j < N; j++) {
      cout << ranks[j] << ' ';
    }
    cout << endl;
  }
	return 0;
}