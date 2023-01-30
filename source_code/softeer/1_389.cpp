#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
int N, K, A, B;
vector<int> S;
int main(int argc, char** argv)
{
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    int tmp;
    cin >> tmp;
    S.push_back(tmp);
  }

  for (int i = 0; i < K; i++) {
    cin >> A >> B;
    double tmp = 0.0;
    for (int j = A; j <=B; j++) {
      tmp += S[j-1];
    }
    printf("%.2f\n", tmp/(B-A+1));
  }
	return 0;
}