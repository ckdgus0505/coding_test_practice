#include <iostream>
#include <string>
using namespace std;
int main(void) {
  string times[5][2];

  for (int i = 0; i < 5; i++) {
    cin >> times[i][0] >> times[i][1];
  }
  int answer = 0;
  for (int i = 0; i < 5; i++) {
    answer += (stoi(times[i][1].substr(0,2))
            - stoi(times[i][0].substr(0,2)))*60;
    answer += (stoi(times[i][1].substr(3,2))
            - stoi(times[i][0].substr(3,2)));
  }
  cout << answer << endl;
  return 0;
}