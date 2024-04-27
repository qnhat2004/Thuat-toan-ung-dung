#include <bits/stdc++.h>
using namespace std;

#define ll long long

unordered_map<ll, ll> g;

ll solve(ll x) {
    if (g.count(x)) return g[x];

    if (x % 2 == 0) return g[x] = solve(x/2);

    if ((x-1) % 4 == 0) {
        ll n = (x - 1) / 4;
        return g[x] = 2 * solve(2*n + 1) - solve(n);
    }

    ll n = (x - 3) / 4;
    return g[x] = 3 * solve(2*n + 1) - 2 * solve(n);
}

int main()
{
    g[1] = 1ll, g[3] = 3ll; 
    
    ll n; 
    cout << "Nhap n = ";
    cin >> n;
    printf("g(%lld) = %lld", n, solve(n));
    return 0;
}