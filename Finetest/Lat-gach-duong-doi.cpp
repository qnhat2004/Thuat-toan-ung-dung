#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "N = "; cin >> n;
    int a = 1, b = 1;
    for (int i = 1; i <= n; ++i) {
        b = 2*a + b;
        a = b - 2*a;
    }
    cout << "So phuong an = " << b;
    return 0;
}