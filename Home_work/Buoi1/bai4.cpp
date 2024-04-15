#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll MAX = 1'000'000'000;

ll fast_pow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    if (res < MAX) return res;

    // Lay 9 chu so dau
    double tmp = log10(res);
    tmp -= (int)tmp;
    tmp = pow(10, tmp);
    cout << "tmp = " << tmp << endl;
    return (ll)(tmp * 1e8); 
}

int main()
{
    ll a, b;
    cin >> a >> b;
    cout << fast_pow(a, b);
    return 0;
}
