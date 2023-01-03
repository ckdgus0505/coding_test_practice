#include<iostream>

using namespace std;
int cache[26];
int solve(int n) {
  if (cache[n]!=0) return cache[n];
  else {
    cache[n] = solve(n-1)*2-1;
    return cache[n];
  }
}

int main(int argc, char** argv)
{
  int N;
  cache[0]=2;
  cin >> N;
  cout << solve(N)*solve(N) << endl;
  
	return 0;
}