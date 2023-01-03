#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
  int a, b;
  cin >> a >> b;

  if (b - a == 0) cout << "same" << endl;
  else if (b - a > 0) cout << "B" << endl;
  else cout << "A" << endl;

	return 0;
}