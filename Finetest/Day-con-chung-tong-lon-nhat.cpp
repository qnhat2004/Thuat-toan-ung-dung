#include <bits/stdc++.h>
using namespace std;

int m, n;
int a[1000], b[1000];

int main()
{
    cout << "Nhap m: "; cin >> m;
    for (int i = 0; i < m; i++) {
        cout << "a[" << i+1 << "] = ";
        cin >> a[i]; 
    }
    cout << "Nhap n: "; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "b[" << i+1 << "] = ";
        cin >> b[i]; 
    }
    
    return 0;
}