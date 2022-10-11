#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>> arr;
int n,m,k,c, cnt = 0;

void growth() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int tmp = 0; // count of adjacent
      if (arr[i][j] > 0) {
        if (i-1>=0 && arr[i-1][j] > 0) tmp++;
        if (i+1<n && arr[i+1][j] > 0) tmp++;
        if (j-1>=0 && arr[i][j-1] > 0) tmp++;
        if (j+1<n && arr[i][j+1] > 0) tmp++;
        arr[i][j]+=tmp;
      }
    }
  }
}
void breeding() {
  queue<pair<pair<int,int>, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int bitmask = 0; // count of adjacent, 1is empty
      if (arr[i][j] > 0) {
        if (i-1>=0 && arr[i-1][j] == 0) {
          bitmask = bitmask | (1<<0); 
        }
        if (i+1<n && arr[i+1][j] == 0) {
          bitmask = bitmask | (1<<1); 
        }
        if (j-1>=0 && arr[i][j-1] == 0) {
          bitmask = bitmask | (1<<2); 
        }
        if (j+1<n && arr[i][j+1] == 0) {
          bitmask = bitmask | (1<<3); 
        }
      }
      if (arr[i][j]>0) q.push(make_pair(make_pair(i,j),bitmask));
    }
  }
  
  while(!q.empty()) {
    int i=q.front().first.first;
    int j=q.front().first.second;
    int bitmask=q.front().second;
    int tmp = 0; // count of adjacent
    for (int i = 0; i < 4; i++) {
      tmp += (bitmask>>i)&1;
    }
    if ((bitmask&(1<<0))==1) {arr[i-1][j] += arr[i][j]/tmp; }
    if ((bitmask&(1<<1))==2) {arr[i+1][j] += arr[i][j]/tmp; }
    if ((bitmask&(1<<2))==4) {arr[i][j-1] += arr[i][j]/tmp; }
    if ((bitmask&(1<<3))==8) {arr[i][j+1] += arr[i][j]/tmp; }
    q.pop();
  }
}

void herbicide() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] < 0)
        arr[i][j]+=1;
    }
  }
}
  
int weeding() {
  int a,b, max = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cnt = arr[i][j];
      if (cnt > 0) {
        for (int l = 1; l <= k; l++) {
          if (i-l>=0 && j-l>=0) {
            if (arr[i-l][j-l]>0) cnt+=arr[i-l][j-l];
            else break;
          }
        }
        for (int l = 1; l <= k; l++) {
          if (i+l<n && j-l>=0) {
            if (arr[i+l][j-l]>0) cnt+=arr[i+l][j-l];
            else break;
          }
        }
        for (int l = 1; l <= k; l++) {
          if (i-l>=0 && j+l<n) {
            if (arr[i-l][j+l]>0) cnt+=arr[i-l][j+l];
            else break;
          }
        }
        for (int l = 1; l <= k; l++) {
          if (i+l<n && j+l<n) {
            if (arr[i+l][j+l]>0) cnt+=arr[i+l][j+l];
            else break;
          }
        }
      }
      if (cnt > max){
        max = cnt;
        a = i;
        b = j;
      }
    }
  }
  cnt = arr[a][b];
  if (cnt > 0) {
    for (int l = 1; l <= k; l++) {
      if (a-l>=0 && b-l>=0) {
        if (arr[a-l][b-l]>0) arr[a-l][b-l]=-c;
        else {
          if (arr[a-l][b-l]>=-c) arr[a-l][b-l]=-c;
            break;
        }
      }
    }
    for (int l = 1; l <= k; l++) {
      if (a+l<n && b-l>=0) {
        if (arr[a+l][b-l]>0) arr[a+l][b-l]=-c;
        else {
          if (arr[a+l][b-l]>-c) arr[a+l][b-l]=-c;
            break;
        }
      }
    }
    for (int l = 1; l <= k; l++) {
      if (a-l>=0 && b+l<n) {
        if (arr[a-l][b+l]>0) arr[a-l][b+l]=-c;
        else {
          if (arr[a-l][b+l]>-c) arr[a-l][b+l]=-c;
            break;
        }
      }
    }
    for (int l = 1; l <= k; l++) {
      if (a+l<n && b+l<n) {
        if (arr[a+l][b+l]>0) arr[a+l][b+l]=-c;
        else {
          if (arr[a+l][b+l]>-c) arr[a+l][b+l]=-c;
            break;
        }
      }
    }
  }
  arr[a][b]=-c;

  return max;
}

void print_arr(){
  cout << "==================" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i][j] << ' ';
    }
    cout << endl;
  }
}
int main(void) {
  int cnt = 0;
  cin >> n >> m >> k >> c;
  arr = vector<vector<int>>(n,vector<int>(n,0));
  int tmp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> tmp;
      if (tmp >= 0) arr[i][j] = tmp;
      else arr[i][j] = -987654321;
    }
  }
  
  for (int i = 0; i < m; i++) {
    growth();
    breeding();
    herbicide();
    cnt += weeding();
  }
  cout << cnt << endl;
  return 0;
}