#include <bits/stdc++.h>
using namespace std;

int a[100], m, n, dp[100][100000];

void gen(int k, int sum) {
    if (k == n) {
        if (sum == m) dp[k][sum] = 1;
        else dp[k][sum] = 0;
        return;
    }
    if (dp[k][sum] != -1) return;
    gen(k+1, sum); // Tính dp[k+1][sum]
    gen(k+1, sum + a[k]); // Tính dp[k+1][sum + a[k]]
    dp[k][sum] = dp[k+1][sum] + ((sum + a[k] <= m) ? dp[k+1][sum + a[k]] : 0);
}

int main() {
    cout << "Nhap m = "; cin >> m;
    cout << "Nhap n = "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    gen(0, 0);
    cout << "Co tat ca " << dp[0][0] << " cach phan tich.";
    return 0;
}
