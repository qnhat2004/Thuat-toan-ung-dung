#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int a[MAX], n, m;

void print(int n) {
    for (int i = 1; i <= n; i++) cout << a[i]; cout << endl;
}
void gen(int k) {
    if (k > n) { print(n); return; }
    for(int i = a[k-1] + 1; i <= m+n-k; i++) {
        a[k] = i; gen(k+1);
    }
}
int main()
{
    cin >> n >> m;
    a[0] = 0;
    gen(1);
    return 0;
}