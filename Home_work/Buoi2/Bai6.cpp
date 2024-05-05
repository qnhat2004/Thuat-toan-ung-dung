#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int n;
vector<vector<int>> dp;
vector<vector<int>> ways;
vector<int> prefixSum; // Lay tong cua doan [p, q] trong O(1)

int findMinPartiton(int p, int q, int totalSum, int sum) { 
    if (p > q) 
        return abs(totalSum - 2 * sum); // sum: Tong hien tai cua cac phan tu da chon
    if (dp[p][sum] != -1)
        return dp[p][sum];
    int pick = findMinPartiton(p + 1, q, totalSum, sum + a[p]);
    int notPick = findMinPartiton(p + 1, q, totalSum, sum);
    return dp[p][sum] = min(pick, notPick);
}

int countWays(int p, int q, int minDiff, int totalSum, int sum = 0) {
    if (p > q)
        return (abs(totalSum - 2 * sum) == minDiff) ? 1 : 0;
    int pick = countWays(p + 1, q, minDiff, totalSum, sum + a[p]);
    int notPick = countWays(p + 1, q, minDiff, totalSum, sum);
    return ways[p][sum] = pick + notPick;
}

int main()
{
    cout << "n = ";
    cin >> n;
    
    // a
    a.resize(n);
    cout << "a[]: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    // prefix sum
    prefixSum.resize(n, 0);
    prefixSum[0] = a[0];
    for (int i = 1; i < n; i++) prefixSum[i] = prefixSum[i - 1] + a[i];

    // dp
    int totalSum = prefixSum[n - 1];
    dp.resize(n, vector<int>(totalSum + 1, -1));

    // ways
    ways.resize(n, vector<int>(totalSum + 1, -1));

    cout << "So test: ";
    int t;
    cin >> t;

    int p, q;
    for (int i = 1; i <= t; i++) {
        cout << "\n#Test " << i << ": \n";
        cout << "p, q = ";
        cin >> p >> q;
        p--, q--;
        int cur_totalSum = p > 0 ? prefixSum[q] - prefixSum[p - 1] : prefixSum[q];
        int minDiff = findMinPartiton(p, q, cur_totalSum, 0);
        dp = vector<vector<int>>(n, vector<int>(totalSum + 1, -1));
        int ways = countWays(p, q, minDiff, cur_totalSum, 0);
        cout << "Min diff = " << minDiff << ", So cach = " << ways << endl;
    }
    return 0;
}
