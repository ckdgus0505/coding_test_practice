#include<iostream>
#include<cmath>

using namespace std;
int H, K, R;
int arr[10241];
int tmp[10241];

void sort(int rank, int s, int e) {
  if (rank == 0) {
    return;
  } else {
    int m = (s+e)/2;
    sort(rank-1, s, m);
    sort(rank-1, m, e);
    int i = s;
    int j = m;
    int k = 0;
    int flag = rank%2;
    while(i < m && j < e) {
      if (flag == 0) tmp[k++] = arr[i++];
      else tmp[k++] = arr[j++];
      flag = !flag;
    }
    if (i < m) while(i < m) tmp[k++] = arr[i++];
    else if (j < e) while(j < e) tmp[k++] = arr[j++];
    for (int i = s, k=0; i < e; i++, k++) {
      arr[i] = tmp[k];
    }
  }
}

int main(int argc, char** argv)
{
  cin >> H >> K >> R;
  int P = (int)pow(2,H);
  for (int i = 0; i < P; i++) {
    for (int j = 0; j < K; j++) {
      cin >> arr[i*K+j];
    }
  }
  sort(H, 0, P*K+1);
  int ret = 0;
  for (int i = 0; i < P*K; i++) {
    cout << arr[i] <<' ';
  } cout << endl;
  for (int i = 0; i < R - H; i++) {
    ret += arr[i];
  }
  cout << ret << endl;
  
  return 0;
}