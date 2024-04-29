#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; 
    cin >> n;

    int a[n];
    for (int &i : a)
        cin >> i;
    
    sort(a, a+n);

    int mi = INT_MAX; // min difference
    for (int i = 0; i < n - 1; ++i)
        mi = min(mi, a[i+1] - a[i]);
    
    for (int i = 0; i < n - 1; ++i)
        if (a[i+1] - a[i] == mi)
            cout << a[i] << " " << a[i+1] << endl;
    return 0;
}