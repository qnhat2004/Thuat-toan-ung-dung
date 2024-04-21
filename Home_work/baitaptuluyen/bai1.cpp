#include <bits/stdc++.h>
using namespace std;

#define ll long long
map<ll, ll> dp;

ll f(ll n) {
    if (n == 1ll)
        return dp[n] = 0;
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