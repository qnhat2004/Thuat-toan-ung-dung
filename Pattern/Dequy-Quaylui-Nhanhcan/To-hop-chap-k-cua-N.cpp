#include <bits/stdc++.h>
using namespace std;

// Cach 1: De quy
// C(k, n) = C(k-1, n-1) + C(k, n-1)
int C(int k, int n) {
    if (k == 0 || k == n) return 1;
    return C(k-1, n-1) + C(k, n-1);
}

// Cach 2: De quy co nho
vector<vector<int>> dp;
int C2(int k, int n) {
    if (k == 0 || k == n) return 1;
    if (dp[k][n] != -1) return dp[k][n];
    return dp[k][n] = C2(k-1, n-1) + C2(k, n-1);
}
int main()
{
    int k, n;
    cin >> k >> n;

    clock_t start;
    
    start = clock();
    cout << C(k, n) << '\n';
    cout << "Time: " << (double)(clock() - start) / CLOCKS_PER_SEC << "\n\n";
	
    start = clock();
    dp.resize(100, vector<int>(100, -1));
    cout << C2(k, n) << '\n';
    cout << "Time: " << (double)(clock() - start) / CLOCKS_PER_SEC << "\n\n";
    return 0;
}
