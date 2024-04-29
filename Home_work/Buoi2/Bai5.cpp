#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int a[n];
    for (int &i : a)
        cin >> i;

    int cnt = 0;
    int l = 0, r = n - 1;
    
    while (l < r) {
        int product = a[l] * a[r];
        if (product > m) {
            r--;
            cnt++;
        }
        else 
            l++;
    }
    cout << cnt << endl;
    return 0;
}