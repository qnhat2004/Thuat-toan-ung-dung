#include <bits/stdc++.h>
using namespace std;

int dp[100][100];

int C(int k, int n) {
    if (k == 0 || k == n) return 1;
    if (dp[k][n] != 0) return dp[k][n];
    return dp[k][n] = C(k, n-1) + C(k-1, n-1);
}

int main()
{
    // memset(dp, 0, sizeof(dp));
    int n, k;
    cout << "nhap n: "; cin >> n;
    cout << "nhap k: "; cin >> k;
    cout << C(k, n);    
    return 0;
}