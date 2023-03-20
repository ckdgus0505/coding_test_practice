#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
int board[500][500];
int twothree[8][2][2] = {{{0,0},{0,1}}, {{0,1},{0,2}}, {{1,0},{1,1}}, {{1,1},{1,2}},
                         {{0,0},{0,2}}, {{1,0},{1,2}}, {{0,0},{1,2}}, {{1,0},{0,2}}};

void init() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }
}

int bar(pair<int, int> now) {
  int tmp1 = 0;
  int tmp2 = 0;
  if (now.first + 3 < N) {
    for (int i = 0; i < 4; i++) tmp1 += board[now.first+i][now.second];
  }

  if (now.second + 3 < M) {
    for (int i = 0; i < 4; i++) tmp2 += board[now.first][now.second+i];
  }
  return max(tmp1, tmp2);
}

int square(pair<int, int> now) {
  int score = 0;
  if (now.first+1 < N && now.second+1 < M) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
          score += board[now.first+i][now.second+j];
      }
    }
  }
  return score;
}

int leftover1(pair<int, int> now) {
  int score = 0;
  int tmp1 = 0;
  int tmp2 = 987654321;
  if (now.first+1 < N && now.second+2 < M) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 3; j++) {
          score += board[now.first+i][now.second+j];
      }
    }
  }
  for (int i = 0; i < 8; i++) {
    tmp1 = board[now.first+twothree[i][0][0]][now.second+twothree[i][0][1]];
    tmp1 += board[now.first+twothree[i][1][0]][now.second+twothree[i][1][1]];
    tmp2 = min(tmp2, tmp1);
  }
  return score - tmp2;
}

int leftover2(pair<int, int> now) {
  int score = 0;
  int tmp1 = 0;
  int tmp2 = 987654321;
  if (now.first+2 < N && now.second+1 < M) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 2; j++) {
          score += board[now.first+i][now.second+j];
      }
    }
  }
  for (int i = 0; i < 8; i++) {
    tmp1 = board[now.first+twothree[i][0][1]][now.second+twothree[i][0][0]];
    tmp1 += board[now.first+twothree[i][1][1]][now.second+twothree[i][1][0]];
    tmp2 = min(tmp2, tmp1);
  }
  return score - tmp2;
}


int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  init();
  int answer = -1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      answer = max(answer, bar(make_pair(i, j)));
      answer = max(answer, square(make_pair(i, j)));
      answer = max(answer, leftover1(make_pair(i, j)));
      answer = max(answer, leftover2(make_pair(i, j)));
    }
  }
  cout << answer << endl;
  return 0;
}