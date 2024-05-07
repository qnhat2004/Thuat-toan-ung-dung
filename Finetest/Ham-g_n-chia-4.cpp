#include <bits/stdc++.h>
using namespace std;

#define ll long long
unordered_map<ll, ll> memo;

ll g(ll n) {
    if (memo.count(n)) return memo[n];
    if (n % 2 == 0) return memo[n] = g(n/2);
    ll k = n/4;
    if (n % 4 == 1) return memo[n] = 2 * g(2*k + 1) - g(k);
    return memo[n] = 3 * g(2*k + 1) - 2 * g(k);
}
int main()
{
    memo[1] = 1ll, memo[3] = 3ll;
    ll n;
    cout << "Nhap n = ";
    cin >> n;
    cout << "g(" << n << ") = " << g(n);
    return 0;
}