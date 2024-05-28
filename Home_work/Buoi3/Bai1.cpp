#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n;
map<ll, ll> m;

ll f(ll x) {
    if (m.count(x)) return m[x];
    ll tmp = x/3 * 2;
    if (x % 3 == 0) return m[x] = f(tmp);
    if (x % 3 == 1) return m[x] = f(tmp) + f(tmp + 1);
    return m[x] = f(tmp) + f(tmp + 1) + f(tmp + 2);
}

int main()
{
    m[0ll] = 0ll, m[1ll] = 1ll, m[2ll] = 2ll;
    cout << "Nhap n = ";
    cin >> n;
    cout << "f(" << n << ") = " << f(n) << endl;
    return 0;
}