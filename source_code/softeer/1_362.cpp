#include <iostream>
using namespace std;
int main(void) {
  int T;
  int tmp1, tmp2;
  cin >> T;
  for (int i = 1; i <= T; i++) {
    cin >> tmp1 >> tmp2;
    cout << "Case #" << i << ": " << tmp1 + tmp2 << endl;
  }
  return 0;
}