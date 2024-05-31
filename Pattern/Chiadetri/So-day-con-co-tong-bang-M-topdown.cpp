#include <bits/stdc++.h>
using namespace std;

const int N = 15;

int a[N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 15, 22, 18, 11, 100, 70 }, S = 70;

int F(int s, int n) {
    if (s == 0) return 1;
    if (n == 0) return 0;
    if (s >= a[n-1]) return F(s, n-1) + F(s-a[n-1], n-1);
    return F(s, n-1);
}

int main()
{
    cout << "So day co tong bang " << S << " la " << F(S, N);
    return 0;
}