#include<iostream>
#include<map>

using namespace std;
unsigned long long K, P, N;
map<unsigned long long, unsigned long long> cache;
unsigned long long pow(unsigned long long p, unsigned long long n) {
  if (n == 0) return 1;
  else if (cache.find(n)!=cache.end()) return cache[n];
  else {
    unsigned long long tmp = 0;
    if (n%2 == 0) {
      tmp = (pow(p, n/2)*pow(p,n/2))%1000000007;
    } else {
      tmp = (((p*pow(p,n/2))%1000000007)*pow(p,n/2))%1000000007;
    }
    cache[n]= tmp;
    return tmp;
  }
}
int main(int argc, char** argv)
{
  cin >> K >> P >> N;
  unsigned long long  answer;

  cout << (K* pow(P,10*N))%1000000007 << endl;
  
	return 0;
}