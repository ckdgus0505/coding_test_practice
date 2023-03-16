#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct{
  int x, y;
} pos;

typedef struct{
  pos R;
  pos B;
  int count;
} Balls;

struct compare{
  bool operator()(Balls &a, Balls &b) {
    return a.count >= b.count;
  }
};

int Y, X;
pos hole;
Balls balls = {0,0,0,0,0};

vector<vector<char>> board;
priority_queue<Balls, vector<Balls>, compare> pq;

void init(){
  cin >> Y >> X;
  board = vector<vector<char>>(Y, vector<char>(X,0));
  for (int y = 0; y < Y; y++) {
    for (int x = 0; x < X; x++) {
      char tmp;
      cin >> tmp;
      board[y][x] = tmp;
      if (tmp == 'R') {
        balls.R.x = x;
        balls.R.y = y;
        board[y][x] = '.';
      }
      else if (tmp == 'B') {
        balls.B.x = x;
        balls.B.y = y;
        board[y][x] = '.';
      }
      else if (tmp == 'O') {
        board[y][x] = tmp;
        hole.y = y;
        hole.x = x;
      }
    }
  }
}

Balls move_left(Balls now) {
  Balls next = {now.R.x, now.R.y, now.B.x, now.B.y, now.count+1};
  for (int x = now.R.x-1; x > 0; x--) {
    if (board[now.R.y][x] == '.') next.R.x = x;
    else if (board[now.R.y][x] == 'O') {
      next.R.x = x;
      break;
    }
    else if (board[now.R.y][x] == '#') {
      break;
    }
  }
  for (int x = now.B.x-1; x > 0; x--) {
    if (board[now.B.y][x] == '.') next.B.x = x;
    else if (board[now.B.y][x] == 'O') {
      next.B.x = x;
      next.count = -1;
      break;
    }
    else if (board[now.B.y][x] == '#') {
      break;
    }
  }
  if (next.R.y == next.B.y && next.R.x == next.B.x && next.count != -1) {
    if (now.R.x < now.B.x) next.B.x++;
    else next.R.x++;
  }
  return next;
}

Balls move_right(Balls now) {
  Balls next = {now.R.x, now.R.y, now.B.x, now.B.y, now.count+1};
  for (int x = now.R.x+1; x < X-1; x++) {
    if (board[now.R.y][x] == '.') next.R.x = x;
    else if (board[now.R.y][x] == 'O') {
      next.R.x = x;
      break;
    }
    else if (board[now.R.y][x] == '#') {
      break;
    }
  }
  for (int x = now.B.x+1; x < X-1; x++) {
    if (board[now.B.y][x] == '.') next.B.x = x;
    else if (board[now.B.y][x] == 'O') {
      next.B.x = x;
      next.count = -1;
      break;
    }
    else if (board[now.B.y][x] == '#') {
      break;
    }
  }
  if (next.R.y == next.B.y && next.R.x == next.B.x && next.count != -1) {
    if (now.R.x < now.B.x) next.R.x--;
    else next.B.x--;
  }
  return next;
}

Balls move_up(Balls now) {
  Balls next = {now.R.x, now.R.y, now.B.x, now.B.y, now.count+1};
  for (int y = now.R.y-1; y > 0; y--) {
    if (board[y][now.R.x] == '.') next.R.y = y;
    else if (board[y][now.R.x] == 'O') {
      next.R.y = y;
      break;
    }
    else if (board[y][now.R.x] == '#') {
      break;
    }
  }
  for (int y = now.B.y-1; y > 0; y--) {
    if (board[y][now.B.x] == '.') next.B.y = y;
    else if (board[y][now.B.x] == 'O') {
      next.B.y = y;
      next.count = -1;
      break;
    }
    else if (board[y][now.B.x] == '#') {
      break;
    }
  }
  if (next.R.y == next.B.y && next.R.x == next.B.x && next.count != -1) {
    if (now.R.y < now.B.y) next.B.y++;
    else next.R.y++;
  }
  return next;
}

Balls move_down(Balls now) {
  Balls next = {now.R.x, now.R.y, now.B.x, now.B.y, now.count+1};
  for (int y = now.R.y+1; y < Y-1; y++) {
    if (board[y][now.R.x] == '.') next.R.y = y;
    else if (board[y][now.R.x] == 'O') {
      next.R.y = y;
      break;
    }
    else if (board[y][now.R.x] == '#') {
      break;
    }
  }
  for (int y = now.B.y+1; y < Y-1; y++) {
    if (board[y][now.B.x] == '.') next.B.y = y;
    else if (board[y][now.B.x] == 'O') {
      next.B.y = y;
      next.count = -1;
      break;
    }
    else if (board[y][now.B.x] == '#') {
      break;
    }
  }
  if (next.R.y == next.B.y && next.R.x == next.B.x && next.count != -1) {
    if (now.R.y < now.B.y) next.R.y--;
    else next.B.y--;
  }
  return next;
}

int bfs() {
  while (!pq.empty()) {
    Balls tmp = pq.top();
    pq.pop();

    Balls tmp2 = move_left(tmp);
    if (tmp2.R.x == hole.x && tmp2.R.y == hole.y && tmp2.count!=-1) return tmp2.count;
    if (tmp2.count >= 1 &&tmp2.count < 10) pq.push(tmp2);
    
    tmp2 = move_right(tmp);
    if (tmp2.R.x == hole.x && tmp2.R.y == hole.y && tmp2.count!=-1) return tmp2.count;
    if (tmp2.count >= 1 &&tmp2.count < 10) pq.push(tmp2);
    
    tmp2 = move_up(tmp);
    if (tmp2.R.x == hole.x && tmp2.R.y == hole.y && tmp2.count!=-1) return tmp2.count;
    if (tmp2.count >= 1 &&tmp2.count < 10) pq.push(tmp2);
    
    tmp2 = move_down(tmp);
    if (tmp2.R.x == hole.x && tmp2.R.y == hole.y && tmp2.count!=-1) return tmp2.count;
    if (tmp2.count >= 1 &&tmp2.count < 10) pq.push(tmp2);
    
  }
  return -1;
}



int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  init();
  pq.push(balls);
  cout << bfs() << endl;

  return 0;
}
