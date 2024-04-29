#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    unordered_map<int, int> m;
    int cnt = 0;
    for (int &i : a) {
        cnt += m[abs(i - k)];
        cnt += m[abs(i + k)];
        m[i]++;
    }
    cout << cnt << endl;
    return 0;
}