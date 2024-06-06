#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    // so sanh a^b va c^d -> so sanh log(a^b) va log(c^d) -> b * log(a) va d * log(c)
    if (b * log(a) > d * log(c))
        cout << "lon hon";
    else if (b * log(a) < d * log(c))
        cout << "nho hon";
    else
        cout << "bang nhau";
    return 0;
}