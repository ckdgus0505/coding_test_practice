#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Dice {
  public:
    int u;
    int d;
    int n;
    int e;
    int w;
    int s;

  Dice() {
    this->u=0;
    this->d=0;
    this->n=0;
    this->e=0;
    this->s=0;
    this->w=0;
  }
  void rotate_east() {
    int num = this->e;
    this->e = this->u;
    this->u = this->w;
    this->w = this->d;
    this->d = num;
  }
  void rotate_west() {
    int num = this->w;
    this->w = this->u;
    this->u = this->e;
    this->e = this->d;
    this->d = num;
  }
  void rotate_north() {
    int num = this->n;
    this->n = this->u;
    this->u = this->s;
    this->s = this->d;
    this->d = num;
  }
  void rotate_south() {
    int num = this->s;
    this->s = this->u;
    this->u = this->n;
    this->n = this->d;
    this->d = num;
  }
};

int N, M, x,y,K;
int map[20][20];
queue<int> order;
Dice dice;

void init(){
  cin >> N >> M >> x >> y >> K;
  for (int i = 0; i < N; i++ ) {
    for (int j = 0; j < M; j++) {
      cin >> map[i][j];
    }
  }
  for (int i = 0; i < K; i++) {
    int tmp;
    cin >> tmp;
    order.push(tmp);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  while (!order.empty()) {
    
    // current x = x; // 세로
    // current y = y; // 가로
    int rotate = order.front();
    order.pop();
    int up = 0;
    switch(rotate) {
      case 1:
        if (y == M-1) break;
        else {
          y+=1;
          dice.rotate_east();
          if (map[x][y] == 0) {
            map[x][y] = dice.d;
          } else {
            dice.d = map[x][y];
            map[x][y] = 0;
          }
          cout << dice.u << endl;
        }
        break;
      case 2:
        if (y == 0) break;
        else {
          y-=1;
          dice.rotate_west();
          if (map[x][y]== 0) {
            map[x][y] = dice.d;
          } else {
            dice.d = map[x][y];
            map[x][y] = 0;
          }
          cout << dice.u << endl;
        }
        break;
      case 3:
        if (x == 0) break;
        else {
          x-=1;
          dice.rotate_north();
          if (map[x][y]== 0) {
            map[x][y] = dice.d;
          } else {
            dice.d = map[x][y];
            map[x][y] = 0;
          }
          cout << dice.u << endl;
        }
        break;
      case 4:
        if (x == N-1) break;
        else {
          x+=1;
          dice.rotate_south();
          if (map[x][y]== 0) {
            map[x][y] = dice.d;
          } else {
            dice.d = map[x][y];
            map[x][y] = 0;
          }
          cout << dice.u << endl;
        }
        break;
    }
    
  }
}