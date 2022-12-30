#include <iostream>
#include <vector>
using namespace std;

int dfs(int current_number, int depth);
vector<int> numbers {4,1,2,1};
int target_number = 0;
int solution = 0;
int main(void){
  cin >> target_number;
  solution = dfs(0, 0);
  cout << solution << endl;
  return 0;
}

int dfs(int current_number, int depth) {
  int ret = 0;
  if (depth == numbers.size()) {
    if (current_number == target_number) {
      return 1;
    }
    else return 0;
  }
  ret += dfs(current_number+numbers[depth], depth+1);
  ret += dfs(current_number-numbers[depth], depth+1);
  return ret;
}