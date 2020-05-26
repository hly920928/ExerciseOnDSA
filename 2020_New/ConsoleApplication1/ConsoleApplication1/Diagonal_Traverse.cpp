#include "mainHeader.h"
using namespace std;
inline bool isOutSide(int M,int N, int x, int y) {
    if (x < 0 || x >=M)return true;
    if (y < 0 || y >=N)return true;
    return false;
}
void produceNext(int M, int N, int& x, int& y) {
    if (x == 0 && y != N - 1) {
        y++;
    }
    else  if (x == M - 1 && y != N - 1) {
        y++;
    }
    else x++;
}
vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {  
    int now_x = 0; int now_y = 0; int M = matrix.size();
    vector<int >ans;
    if (M == 0)return ans;
    int N = matrix[0].size();
    if (N== 0)return ans;
    char dir = 'U';
    while (true) {
        ans.push_back(matrix[now_x][now_y]);
        if (now_x == M - 1 && now_y == N - 1)break;
        int next_x = now_x; int next_y= now_y;
        if (dir == 'U') {
            next_x--; next_y++;
        }
        else {
            next_x++; next_y--;
        }
        if (!isOutSide(M, N, next_x, next_y)) {
            now_x = next_x;
            now_y = next_y;
        }
        else {
            produceNext(M, N, now_x, now_y);
            if (dir == 'U')dir = 'D';
            else dir = 'U';
    
        }
    }
    return ans;
}

 