#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;   
    int a[n]; 
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a+n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int d = a[j] - a[i];
            int next = a[j] + d;
            bool check = true;
            for (int k = 2; k < 5; ++k) {
                if (binary_search(a, a+n, next)) next += d;
                else check = false;
            }
            if (check) cnt++;
        }
    }
    cout << cnt;
    return 0;
}