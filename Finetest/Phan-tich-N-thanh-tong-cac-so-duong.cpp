#include <bits/stdc++.h>
using namespace std;

int n, a[100];

void print(int sz) {
    cout << n << " = " << a[0];
    for (int i = 1; i <= sz; i++) 
        cout << "+" << a[i];
    cout << endl;
}
void gen(int k, int sz, int last) { // sz: size - kich thuoc day hien tai, last: so lon nhat co the chon cho den nay
    if (k == 0) {
        print(sz-1);
        return;
    }
    for (int i = min(k, last); i >= 1; i--) {
        a[sz] = i;
        gen(k - i, sz + 1, i);
    }
}
int main()
{
    cout << "Nhap n = ";
    cin >> n;
    gen(n, 0, n);
    return 0;
}