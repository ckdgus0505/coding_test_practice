#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> arr;

int bsearch(int start, int end, int find, int depth) {
  int mid = (start+end)/2;
  if (find == mid) return depth;
  if (find < mid) return bsearch(start, mid, find, depth+1);
  else return bsearch(mid+1, end, find, depth+1);
  return -1;
}

int main(void){
  int num;
  cin >> num;
  cout << bsearch(1,987654321, num, 0) << endl;
}