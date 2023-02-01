#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <typeinfo>
#define INF 987654321
#define mINF -987654321
using namespace std;
int M[101][101]; // i~j 까지의 연산 중 최댓값
int m[101][101]; // i~j 까지의 연산 중 최솟값
int calc_max(vector<string>&, int, int);
int calc_min(vector<string>&, int, int);

int solution(vector<string> arr)
{
    for (int i = 0; i < 101; i++) {
        fill_n(M[i], 101, mINF);
        fill_n(m[i], 101, INF);    
    }
        
    int answer = -1;
    
    answer = calc_max(arr, 0, arr.size()-1);
    return answer;
}

int calc_max(vector<string>& arr, int a, int b) {
    if (M[a/2][b/2] != mINF) return M[a/2][b/2];
    else if (a == b) {
        M[a/2][b/2] = stoi(arr[a]);
    } else {
        int tmp_max = mINF;
        for (int i = a; i < b; i+=2) {
            if (arr[i+1] == "+")
                tmp_max = max(tmp_max, calc_max(arr, a, i) + calc_max(arr, i+2, b));
            else tmp_max = max(tmp_max, calc_max(arr, a, i) - calc_min(arr, i+2, b));
        }
        M[a/2][b/2] = tmp_max;
    }
    return M[a/2][b/2];
}

int calc_min(vector<string>& arr, int a, int b) {
    if (m[a/2][b/2] != INF) return m[a/2][b/2];
    else if (a == b) {
        m[a/2][b/2] = stoi(arr[a]);
    } else {
        int tmp_min = INF;
        for (int i = a; i < b; i+=2) {
            if (arr[i+1] == "+")
                tmp_min = min(tmp_min, calc_min(arr, a, i) + calc_min(arr, i+2, b));
            else tmp_min = min(tmp_min, calc_min(arr, a, i) - calc_max(arr, i+2, b));
        }
        m[a/2][b/2] = tmp_min;
    }
    return m[a/2][b/2];
}