#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cout << "Nhap m = "; cin >> m;
    cout << "Nhap n = "; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        printf("a[%d] = ", i);
        cin >> a[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i][j] = dp[i-1][j];
            if (j >= a[i-1]) {
                dp[i][j] += dp[i-1][j - a[i-1]];
            }
        }
    }

    cout << "Co tat ca " << dp[n][m] << " cach phan tich.";
    return 0;
}