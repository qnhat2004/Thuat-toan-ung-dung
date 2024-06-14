#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
const int MAXK = 5000;
int n, k;
int dp[MAXN][MAXN][MAXK];

int gen(int cur, int last, int product) {
    if (cur == 0) {
        return product >= k;
    }
    if (dp[cur][last][product] != -1) return dp[cur][last][product];
    dp[cur][last][product] = 0;
    for (int i = min(cur, last); i >= 1; i--) {
        // Check for potential overflow before multiplication
        if (product > k / i) {
            dp[cur][last][product] += gen(cur - i, i, k);  // Treat as overflow, set product to at least k
        } else {
            dp[cur][last][product] += gen(cur - i, i, product * i);
        }
    }
    return dp[cur][last][product];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cout << "N = "; cin >> n;
    cout << "K = "; cin >> k;
    cout << "So cach phan tich cap K = " << gen(n, n, 1);
    return 0;
}

