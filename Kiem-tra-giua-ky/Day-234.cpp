#include <bits/stdc++.h>
using namespace std;

int n;
const int mod = 1e9 + 7;
long long dp[100000];

long long cong(const long long &a, const long long &b)
{
    long long result = a + b;
    if (result >= mod)
        result -= mod;
    return result;
}

long long gen(long long k)
{
    if (k == 0)
        return 1;
    if (k < 0)
        return 0;
    if (dp[k] != -1)
        return dp[k];
    long long res = 0;
    for (int j = 2; j <= 4; j++)
        res = cong(res, gen(k - j));
    return dp[k] = res;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    cout << gen(n) << endl;
    return 0;
}