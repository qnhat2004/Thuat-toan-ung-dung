#include <bits/stdc++.h>
using namespace std;

const int N = 100, W = 1000;
int a[N], b[N];

void init() {
    for (int i = 0; i < N; i++) {
        a[i] = rand() % 10;
        b[i] = rand() % 10;
    }
}

// De quy co nho
int dp[1000][1000];
int dequy(int i, int w) {
    if (i == N || w == 0) return 0; 
    if (dp[i][w] != -1) return dp[i][w];
    if (w < a[i]) return dp[i][w] = dequy(i+1, w);
    return dp[i][w] = max(dequy(i+1, w), dequy(i+1, w - a[i]) + b[i]);
}

// Quy hoach dong
// Y tuong: Voi moi do vat i, xet xem voi trong luong j co the dat gia tri lon nhat la bao nhieu
int qhd(int w) {
    int dp[N+1][W+1]; // dp[i][j]: tong gia tri lon nhat co the dat duoc khi xet den vat thu i va trong luong j
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
            if (j < a[i-1]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i-1]] + b[i-1]);
        }
    }
    return dp[N][W];
} 

/*  
* Cong thuc truy hoi: dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i]] + b[i])
*/
int main()
{
    init();
    memset(dp, -1, sizeof(dp));
    cout << "De quy: " << dequy(0, W) << endl; 
    cout << "Quy hoach dong: " << qhd(W) << endl;
    return 0;
}