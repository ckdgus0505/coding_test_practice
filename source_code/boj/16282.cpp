#include <iostream>
#include <cmath>
using namespace std;
long long N;
long long cache[62];

long long square(int b) {
  if (cache[b] != 0) return cache[b];
  else if (b%2 == 0) return square(b/2)*square(b/2);
  else return 2*square(b/2)*square(b/2);
}

long long max_value(int i) {
  if (cache[i+1] == 0) cache[i+1] = square(i+1);
  return cache[i+1]*(i+1)-1;
}

int main(void) {
  cache[0]=1;
  cin >> N;
  for (int i = 1; i < 57; i++) {
    long long tmp = max_value(i);
    if (tmp >= N) {
      cout << i << endl;
      break;
    }
  }
}