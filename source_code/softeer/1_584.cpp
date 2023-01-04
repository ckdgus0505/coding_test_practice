#include<iostream>
#include<vector>

using namespace std;
int N, M;
vector<pair<int, int>> elevator;
vector<pair<int, int>> test;
int main(int argc, char** argv)
{
  int max = 0;
  cin >> N >> M;
  int prev = 0;
  for (int i = 0; i < N; i++) {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    prev += tmp1;
    elevator.push_back(make_pair(prev, tmp2));
  }
  prev = 0;
  for (int i = 0; i < M; i++) {
    int tmp1, tmp2;
    cin >> tmp1 >> tmp2;
    prev += tmp1;
    test.push_back(make_pair(prev, tmp2));
  }

  int i=0, j=0;
  while (i < N && j < M) {
    if (test[j].second - elevator[i].second > max) {
      max = test[j].second - elevator[i].second;
    }
    if (elevator[i].first < test[j].first) {
      i++;
    } else if (elevator[i].first > test[j].first) {
      j++;
    } else {
      i++;
      j++;
    }
  }
  cout << max << endl;
	return 0;
}