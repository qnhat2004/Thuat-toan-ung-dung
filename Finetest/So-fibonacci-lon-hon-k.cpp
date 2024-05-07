#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll a = 0, b = 1, c, k;   
    cin >> k;
    if (k < 0) {
        cout << 0;
        return 0;
    }
    while (a <= k) {
        b = a + b;
        a = b - a;
    }
    cout << a;
    return 0;
}