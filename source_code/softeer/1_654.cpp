#include<iostream>
#include<vector>
/* 풀이 아이디어
	i < j < k 이면서
	ai < aj && ak < ai 이면 정렬 불가
*/ 
using namespace std;

int main(int argc, char** argv)
{
	vector<int> arr;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	long long answer = 0;
	for (int i = 0; i < N-2; i++) {
    long long cnt = 0;
		for (int k = i+1; k < N; k++) {
      if (arr[i] < arr[k]) cnt++;
      else  answer += cnt;
    }
	}
	cout << answer << endl;
	return 0;
}