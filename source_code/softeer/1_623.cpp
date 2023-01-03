#include<iostream>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
  int M, N, K;
  string secret_code;
  string key_stream;
  int count = -1;
  cin >> M >> N >> K ;
  for (int i = 0; i < M; i++) {
    string z;
    cin >> z;
    secret_code+=z;
  }
  for (int i = 0; i < N; i++) {
    string z;
    cin >> z;
    key_stream+=z;
  }

  for (int i = 0; i < N-M+1; i++) {
    if ( secret_code.compare( key_stream.substr(i, M) ) == 0 ) {
      count = 0;
      break;
    }
    
  }
  if (count == 0 ) cout << "secret" << endl;
  else cout << "normal" << endl;
  return 0;
}