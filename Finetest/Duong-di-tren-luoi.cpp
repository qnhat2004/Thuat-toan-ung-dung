#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<vector<int>> dp;

int solve(int m, int n) {
    if (m == 0 || n == 0) return 1;
    if (dp[m][n] != -1) return dp[m][n];
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int u = m + dx[i];
        int v = n + dy[i];
        if (u >= 0 && u <= m && v >= 0 && v <= n) {
            cnt += solve(u, v);
        }
    }
    return dp[m][n] = cnt;
}
int main()
{
    int m, n;
    cout << "Nhap M = "; cin >> m;
    cout << "Nhap N = "; cin >> n;
    cout << "So cach = ";
    dp.resize(m+1, vector<int>(n+1, -1));
    cout << solve(m, n);
    return 0;
}