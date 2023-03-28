#include <iostream>
#include <vector>
#include <set>
using namespace std;
int G, P;
vector<int> planes;
set<int> gates;


void init() {
  cin >> G >> P;
  for (int i = 0; i < P ; i++) {
    int tmp;
    cin >> tmp;
    planes.push_back(tmp);
  }
  for (int i = 1; i <= G; i++) {
    gates.insert(-i);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  int answer = 0;


  for (auto plane : planes) {
    if (gates.count(plane)==1) {
      answer ++;
      gates.erase(plane);
    } else {
      auto tmp = gates.lower_bound(-plane);
      if (tmp != gates.end()) {
        answer ++;
        gates.erase(tmp);
      } else break;
    }
  }
  cout << answer << endl;
  return 0;
}