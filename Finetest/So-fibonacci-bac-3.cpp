#include <bits/stdc++.h>
using namespace std;

#define ll long long
unordered_map<ll, ll> m;

ll f(ll n) {
    if (m.count(n)) return m[n];

    ll k;

    if (n % 3 == 0) {
        k = n/3;
        return m[3*k] = f(2*k);
    }
    if ((n-1) % 3 == 0) {
        k = (n-1)/3;
        return m[3*k+1] = f(2*k + 1) + f(2*k);
    }

    k = (n-2)/3;
    return m[3*k+2] = f(2*k) + f(2*k + 1) + f(2*k + 2);
}

int main()
{
    m[0] = 0ll, m[1] = 1ll, m[2] = 2ll;
    ll n;
    cout << "Nhap n = ";
    cin >> n;
    printf("f(%lld) = %lld\n", n, f(n));
    return 0;
}