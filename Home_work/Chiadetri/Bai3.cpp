#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n); // O(nlogn)
    int _min = INT_MAX;
    for (int i = 0; i < n - 1; i++) _min = min(_min, a[i+1] - a[i]);
    cout << _min;
    return 0;
}