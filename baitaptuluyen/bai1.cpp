#include <bits/stdc++.h>
using namespace std;

#define ll long long
unordered_map<ll, ll> dp;

ll f(ll n) {
    if (n == 1ll)
        return dp[n] = 0;
    if (dp.count(n)) // Nếu n đã được tính toán trước đó
        return dp[n];
    if (n & 1)
        dp[n] = 1ll + f(3*n + 1ll);
    else
        dp[n] = 1ll + f(n/2ll);
    return dp[n];
}

int main()
{
    ll n;
    cin >> n;
    cout << f(n) << endl;
    return 0;
}