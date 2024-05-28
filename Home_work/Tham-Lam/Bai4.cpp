#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Nhap N = ";
    cin >> n;
    int a[n];
    cout << "Nhap san luong sua cua " << n << " con bo: ";
    for (int i = 0; i < n; i++) cin >>  a[i];
    sort(a, a+n, greater<int>());
    int sum = 0, giam = 0;
    for (int i = 0; i < n; i++) {
        sum += ((a[i] - giam > 0) ? a[i] - giam : 0);
        giam++;
    }
    cout << "San luong sua lon nhat co the thu duoc: " << sum << endl;
    return 0;
}