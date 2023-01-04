#include<iostream>
#include<cstdio>

using namespace std;
unsigned int seven_seg[10];
int main(int argc, char** argv)
{
  int T, a, b;
  
  seven_seg[0] = 0b01110111;  //119
  seven_seg[1] = 0b00010010;  //18
  seven_seg[2] = 0b01011101;  //93
  seven_seg[3] = 0b01011011;  //91
  seven_seg[4] = 0b00111010;  //58
  seven_seg[5] = 0b01101011;  //107
  seven_seg[6] = 0b01101111;  //111
  seven_seg[7] = 0b01110010;  //114
  seven_seg[8] = 0b01111111;  //127
  seven_seg[9] = 0b01111011;  //123
  
  cin >> T;
  for (int i = 0 ; i < T; i++) {
    int answer = 0;
    cin >> a >> b;

    for (int j = 0; j < 5; j++) {
      unsigned int calc_a, calc_b;
      
      if (a == 0) calc_a = 0;
      else {
        calc_a = seven_seg[a%10];
        a/=10;
      }

      if (b == 0) calc_b = 0;
      else {
        calc_b = seven_seg[b%10];
        b/=10;
      }
      unsigned int tmp = calc_a ^ calc_b;
      for (int i = 0; i < 8; i++) {
        answer += tmp&1;
        tmp = tmp >> 1;
      }
    }
  cout << answer << endl;
  }

  
	return 0;
}