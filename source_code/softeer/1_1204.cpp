#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>

/* 풀이 아이디어 :
   완전 탐색
   이진 탐색 --> to do
   정렬
*/

using namespace std;
vector<unsigned long long> arr;
int N;
unsigned long long B; // number of computer & costs

unsigned long long calc(unsigned long long m, vector<unsigned long long>& arr) {
  unsigned long long cost = 0;
    for (int j = 0; j < arr.size(); j++) {
      if (arr[j] < m) {
        cost += (m-arr[j])*(m-arr[j]);
      } else break;
      if (cost > B) { // cost 가 B 이상이면 이 이상의 계산은 의미가 없음, 시간 절약과 overflow 를 막기위해 break 해줌
        break;
      }
    }
  return cost;
}

int main(int argc, char** argv)
{
  cin >> N >> B;
  
  for (int i = 0; i < N; i++) {
    unsigned long long tmp;
    cin >> tmp;
    arr.push_back(tmp);
  }
  sort(arr.begin(), arr.end());

  unsigned long long cost = 0;
  unsigned long long s = 1;
  unsigned long long e = 2000000001; // computer가 가질 수 있는 최고 성능
  unsigned long long m;
  /*
   * 최소 성능을 기준으로 해당 성능으로 올릴 때 필요한 금액을 계산
   * 최소 성능을 binary search로 찾으면 O(log) 의 시간 복잡도로 탐색 가능
  */

  while (true) {
    m = (s + e)/2;
    cost = calc(m, arr);
    
    // cout << s << ", " << e << ", " << m << ", " << cost << ", " << B << endl;
 
    if (s == e-1) {
      if (calc(e, arr) <= B) {
        cout << e << endl;
        break;
      }
      else {
        cout << s << endl;
        break;
      }
    } else if (s == e) {
      cout << s << endl;
      break;
    }
    else if ( cost <= B ) s = m;
    else e = m-1;
  }
  
  return 0;
}