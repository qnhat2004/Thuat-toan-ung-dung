#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll mod = 1'000'000'000;

ll fast_pow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res % mod;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << fast_pow(a, b);
    return 0;
}
