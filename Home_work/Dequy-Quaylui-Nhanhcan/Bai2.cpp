#include <bits/stdc++.h>
using namespace std;

int n, a[100];

void print() {
    for (int i = 0; i < n; i++) cout << a[i] << "";
    cout << endl;
}

void gen(int k) {
    if (k >= n) {
        print();
        return;
    }
    for (int i = 0; i <= 2; i++) {
        a[k] = i;
        gen(k + 1);
    }
}

int main()
{
    cout << "Nhap n = ";
    cin >> n;    
    gen(0);
    return 0;
}