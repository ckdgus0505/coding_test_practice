#include<iostream>

using namespace std;
long unsigned int K, P, N;
long unsigned int cache[1000002];
long unsigned int pow(long unsigned int a, long unsigned int b) {
  if (cache[b]==0) {
    if( b == 0) {
      cache[b] = 1;
    } else if (b == 1) {
      cache[b] = a;
    }
    else if (b%2 == 0) {
      cache[b] = ( pow(a, b/2) * pow(a, b/2) )%1000000007;
    }
    else {
      cache[b] = ( (a*(pow(a,(b-1)/2)))%1000000007 * pow(a,(b-1)/2)) %1000000007;
    }
  }
  return cache[b];
}

int main(int argc, char** argv)
{
  cin >> K >> P >> N;
  cout << (K*pow(P, N))%1000000007 << endl;
	return 0;
}