#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "N = "; cin >> n;
    int a = 1, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = 2*a + b;
        a = b;
        b = c;
    };
    cout << "So phuong an = " << b;
    return 0;
}