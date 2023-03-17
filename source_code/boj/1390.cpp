#include<iostream>
#include<vector>
#include<deque>
#include<set>
using namespace std;

typedef struct{ // dir : right=0, down=1 left=2 up=3; return direction
  int y;
  int x;
} pos;

int rdlu[4][2] = {{0,1}, {1,0}, {0,-1}, {-1, 0}};

typedef struct{
  int y;
  int x;
} Apple;

struct Apple_comp {
  bool operator() (const Apple& a, const Apple& b) const {
    if (a.x < b.x) return 1;
    else if (a.x > b.x) return 0;
    if (a.y < b.y) return 1;
    return 0;
  }
};

typedef struct{
  int time;
  char dir;
} Move;

int N, K, L;
int dir = 0;
deque<pos> sneak;
vector<vector<bool>> board;
set<Apple, Apple_comp> apples;
vector<Move> moves;
void init() {
  cin >> N;
  board = vector<vector<bool>>(N, vector<bool>(N,0));
  board[0][0]=true;
  sneak.push_back(pos{0,0});
  
  cin >> K;
  for (int i = 0; i < K; i++) {
    int a, b;
    cin >> a >> b;
    Apple apple = {a-1,b-1};
    apples.insert(apple);
  }

  cin >> L;
  for (int i = 0; i < L; i++) {
    int a;
    char b;
    cin >> a >> b;
    Move move = {a,b};
    moves.push_back(move);
  }
  
}

// if game end, retun -1;
bool move_after_one_sec() {
  pos head = {sneak.front().y + rdlu[dir][0], sneak.front().x + rdlu[dir][1]};
  if (head.x < 0 || head.y < 0 || head.x >=N || head.y >= N) return false;
  if (!board[head.y][head.x]) {
    sneak.push_front(head);
    board[head.y][head.x] = true;
  } else {
    return false;
  }
  Apple apl = {head.y, head.x};
  if (apples.find(apl) != apples.end()) {
    apples.erase(apl);
  } else {
    board[sneak.back().y][sneak.back().x]=false;
    sneak.pop_back();
  }

  return true;
}

void turn_after_one_sec(char C) {
  if (C == 'L') {
    dir = int((dir+3)%4);
  }  else if (C == 'D') {
    dir = int((dir+5)%4);
  }
}
void print_board() {
  cout << dir << endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << board[i][j];
    }
    cout << endl;
  }

  for (auto T : apples) {
    cout << T.x << "," << T.y << endl;
  }
  
  cout << apples.size() << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  init();
  int t = 0;
  bool ret = true;
  int i=0;
  for (i=1;;i++) {
    ret = move_after_one_sec();

    if (moves[t].time == i) {
      turn_after_one_sec(moves[t].dir);
      t++;
    }
       
    if (ret == false) {
      break;
    }
  }
  cout << i << endl;
  return 0;
}
