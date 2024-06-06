#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll a, b, c;

ll fast_pow() {
    ll res = 1;
    while(b) {
        if (b & 1) res = (res % c * a % c) % c;
        a = (a % c * a % c) % c;
        b >>= 1;
    }
    return res;
}

int main()
{
    cout << "Nhap a, b, c: ";
    cin >> a >> b >> c;
    cout << fast_pow();
    return 0;
}