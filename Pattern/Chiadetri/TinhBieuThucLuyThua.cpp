#include <bits/stdc++.h>
using namespace std;

// Tinh Px = a[0]x^n + a[1]x^(n-1) + ... + a[n-1]x + a[n]
double P1(double a[], int n, double x)
{
    double t = 0;
    for (int i = 0; i <= n; i++)
    {
        double q = 1;
        for (int j = 0; j < (n - i); j++)
            q *= x; // Tinh x^(n-i)
        t += a[i] * q;
    }
    return t;
}

// Tinh Px = a[n] + x.a[n-1] + x^2.a[n-2] + ... + x^n*a[0]
double P2(double a[], int n, double x)
{
    double t = 0, q = 0;
    for (int i = n; i >= 0; i--)
    {
        t += a[i] * q;
        q *= x;
    }
    return t;
}

// Tinh Px = a[0]x^n + a[1]x^(n-1) + ... + a[n-1]x + a[n]
double P3(double a[], int n, double x)
{
    if (n == 0) return a[0];
    return x * P3(a, n-1, x) + a[n];
}

double P31(double a[], int n, double x) {
    double t = a[0];
    for (int i = 1; i <= n; i++) {
        t = x * t + a[i];
    }
    return t;
}

int main()
{

    return 0;
}