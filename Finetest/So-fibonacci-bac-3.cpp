#include <bits/stdc++.h>
using namespace std;

#define ll long long
unordered_map<ll, ll> memo; // Memory - Luu ket qua cua ham f(n)

ll f(ll n) {
    if (memo.count(n)) return memo[n];
    ll k = n/3;
    if (n % 3 == 0) {
        memo[n] = f(2*k);
    } else if (n % 3 == 1) {
        memo[n] = f(2*k) + f(2*k + 1);
    } else {
        memo[n] = f(2*k) + f(2*k + 1) + f(2*k + 2);
    }
    return memo[n];
}
int main()
{
    memo[0] = 0ll, memo[1] = 1ll, memo[2] = 2ll;
    ll n;
    cout << "Nhap n = ";
    cin >> n;
    cout << "f(" << n << ") = " << f(n);
    return 0;
}