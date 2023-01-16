#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;
int cipher[5][5];
bool chk[26];
map<int, pair<int, int>> m;
int main(int argc, char** argv)
{
  string message;
  string key;
  cin >> message;
  cin >> key;
  
  int cnt = 0;
  for (int i = 0 ; i < key.length(); i++) {
    int index = key[i] -'A';
    if (chk[index] == true) {continue;}
    else {
      cipher[cnt/5][cnt%5]=key[i];
      m.insert(make_pair(key[i], make_pair(cnt/5, cnt%5)));
      chk[index] = true;
      cnt++;
    }
  }
  chk['J'-'A']=true;
  for (int i = 0; i < 26; i++) {
    if (chk[i] == true) continue;
    else {
      cipher[cnt/5][cnt%5] = 'A'+i;
      m.insert(make_pair('A'+i, make_pair(cnt/5, cnt%5)));
      chk[i]=true;
      cnt++;
    }
  }
  int len = message.length();
  for (int i = 0; i < len; i+=2) {
    if (message[i] == message[i+1] ) {
      if (message[i] != 'X') {
        message.insert(message.begin()+i+1, 'X');
      } else {
        message.insert(message.begin()+i+1, 'Q');
      }
      len++;
    }
  }
  if (message.length()%2 == 1) {
    message.insert(message.end(), 'X');
  }

  string answer = "";

  for (int i = 0; i < message.length(); i+=2) {
    int c1, r1, c2, r2;
    r1 = m[message[i]].first;
    c1 = m[message[i]].second;
    r2 = m[message[i+1]].first;
    c2 = m[message[i+1]].second;
    if (r1 == r2) {
      answer += cipher[r1][(c1+1)%5];
      answer += cipher[r2][(c2+1)%5];
    } else if (c1 == c2) {
      answer += cipher[(r1+1)%5][c1];
      answer += cipher[(r2+1)%5][c2];
    } else {
      answer += cipher[r1][c2];
      answer += cipher[r2][c1];
    }
  }
  
  cout << answer << endl;
	return 0;
}