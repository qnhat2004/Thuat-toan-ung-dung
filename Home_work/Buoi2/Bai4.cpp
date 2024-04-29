#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int &i : a)
        cin >> i;

    partial_sort(a, a+k, a+n);
    cout << "Min difference: " << a[k-1] - a[0] << endl;
    for (int i = 0; i < k; ++i)
        cout << a[i] << ' ';   
    return 0;
}