#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n, greater<int>());
    int mx = a[0], cnt = 1, i = 1;
    while (mx > 0 && i < n) {
        cnt++;
        mx = min(mx - 1, a[i++]);
    }
    cout << cnt;
    return 0;
}