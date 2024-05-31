#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n;

int main()
{
    cout << "Nhap n = ";
    cin >> n;
    ll Xi = 1;     
    for (ll i = 1ll; i <= n; i++) {
        Xi = Xi * (i + (n - i) * (n - i));
    }
    cout << "X(" << n << ") = " << Xi;
    return 0;
}