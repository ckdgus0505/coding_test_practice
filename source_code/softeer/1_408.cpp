#include <iostream>
#include <string>
using namespace std;
int main(void) {
  string a;
  for (int i = 0; i < 8; i++) {
    string tmp;
    cin >> tmp;
    a+=tmp;
  }
  if (a.compare("12345678")==0)
    cout << "ascending" << endl;
  else if (a.compare("87654321")==0)
    cout << "descending" << endl;
  else
    cout << "mixed" << endl;
  return 0;
}