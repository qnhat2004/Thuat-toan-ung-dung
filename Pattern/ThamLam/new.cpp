#include <bits/stdc++.h>
using namespace std;

const int N = 5;
int a[N] = { 1, 5, 10, 25, 100 }, b[N] = { 0 }, m, t = 0;

void print() {
    for (int i = 0; i < N; i++) {
        cout << a[i] << ": " << b[i] << endl;
    }
    cout << "Tong so xu: " << t << endl;
}

void recurse(int k, int cur) {
    if (k >= m) return;
    b[k] = m / a[k];
    t += m / a[k];
    if (a[k] > 0) cout << "So xu " << a[k] << ": " << m / a[k] << endl;
    recurse(k+1, cur - (m/a[k]) * a[k]);
}

void greedy() {
    sort(a, a+N, greater<int>());
    int i = 0;
    while(m > 0) {
        if (m > a[i]) {
            b[i] = m/a[i];
            t += m/a[i];
            m -= (m/a[i]) * a[i];
        }
        else i++;
    }
}

int main()
{
    cout << "Nhap so tien m: "; cin >> m;
    greedy();
    print();
    recurse(0, m);
    print();
    return 0;
}