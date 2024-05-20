#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll a = 0, b = 1, c = 1;
    ll k;
    cin >> k;
    if (k < 0) {
        cout << 0;
        return 0;
    }
    while (b <= k) {
        c = a + b;
        a = b;
        b = c;
    }
    cout << c;
    return 0;
}