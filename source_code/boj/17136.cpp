#include <iostream>
#include <set>
#include <vector>

using namespace std;
int arr[10][10];
set<pair<int, int>> ones;
int papers[5] = {5,5,5,5,5};

void init() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      int tmp;
      cin >> arr[i][j];
      if (arr[i][j]==1) ones.insert(make_pair(i,j));
    }
  }
}

void recover(vector<pair<int, int>>& covered) {
  for (auto i : covered) {
    arr[i.first][i.second] = 1;
  }
  covered.clear();
}

vector<pair<int, int>> cover(int n, int x, int y) {
  vector<pair<int, int>> s;
  if (x+n >= 10 && y+n >= 10) return s;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[x+i][x+j] == 1) {
        s.push_back(make_pair(x+i, x+j));
        arr[x+i][x+j] = 0;
      } else {
        recover(s);
        return s;
      }
    }
  }

  return s;
}



int dfs(int x, int y) {
  int ret = 0;
  for (int i = 0; i <5; i++) {
    if (arr[i] < 0) return ret;
  }

  for (int l = 10*x+y; l < 100; l++) {
    int i = l/10;
    int j = l%10;
    if (arr[i][j] == 1) {
      int tmp = 100;
      for (int k = 1; k <= 5; k++) {
        vector<pair<int, int>> s = cover(k, i, j);
        if (!s.empty()) {
          for (auto i : s)
            ones.erase(make_pair(i.first, i.second));
          papers[k-1]-=1;
          tmp += min(tmp, dfs(i,j));
          for (auto i : s)
            ones.insert(make_pair(i.first, i.second));
          recover(s);
          papers[k-1]+=1;
        }
      }
      ret += tmp;
    }
  }

  return ret;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  int answer = 0;

  answer = dfs(0,0);

  cout << answer << endl;
  return 0;
}