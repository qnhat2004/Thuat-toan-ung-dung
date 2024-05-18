#include <bits/stdc++.h>
using namespace std;

int a[100], m, n, cnt = 0, dp[100][100000];

int gen(int k, int sum) {
    if (k >= n) {
        if (sum == m) return 1;
        return 0;
    }
    if (dp[k][sum] != -1) return dp[k][sum];
    dp[k][sum] = 0;
    dp[k][sum] += gen(k+1, sum);
    dp[k][sum] += gen(k+1, sum + a[k]);
    return dp[k][sum];
}
int main() {
    cout << "Nhap m = "; cin >> m;
    cout << "Nhap n = "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    int cnt = gen(0, 0);
    cout << "Co tat ca " << cnt << " cach phan tich.";
    return 0;
}