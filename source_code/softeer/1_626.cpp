#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cstdio>
using namespace std;
int N, M;
vector<string> room_name;
map<string, int> rooms;
vector<vector<int>> time_table;

vector<pair<int, int>> check_times(vector<int>& room) {  
  vector<pair<int, int>> ret;
  int start = -1;
  int end = -1;
  for (int i = 0; i < 9; i++) {
    if (room[i] == 0) {
      if (start == end) 
        start = i;
      if (room[i+1] == 1) {
        end = i+1;
        ret.push_back(make_pair(start, end));
        start = end;
      }
    }
  }
  return ret;
}

int main(int argc, char** argv)
{
  cin >> N >> M;
  time_table = vector<vector<int>>(N, vector<int>(10, 0));
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    room_name.push_back(s);
    rooms.insert(make_pair(s, i));
    time_table[i][9] = 1;
  }
  sort(room_name.begin(), room_name.end());
  for (int i = 0 ; i < M; i++) {
    string r;
    int s, t;
    cin >> r >> s >> t;
    for (int i = s-9; i < t-9; i++) {
      time_table[rooms[r]][i]=1;
    }    
  }

  for (int i = 0; i < N; i++) {
    if (i != 0) cout << "-----" << endl;
    cout << "Room " << room_name[i] << ':' << endl;
    vector<pair<int, int>> tmp;
    tmp = check_times(time_table[rooms[room_name[i]]]);
    if (tmp.size() == 0) {
      cout << "Not available" << endl;
    } else {
      cout << tmp.size() << " available:" << endl;
    }
    for (int k = 0; k < tmp.size(); k++) {
      printf("%02d-%02d\n",tmp[k].first+9, tmp[k].second+9 );
    }
  }
  
	return 0;
}