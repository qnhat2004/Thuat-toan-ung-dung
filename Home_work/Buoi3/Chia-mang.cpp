#include <bits/stdc++.h>
using namespace std;

int a[100], n, b[] = {0, 1, 2, 3, 4, 5, 8, 7, 7, 10, 20, 1 }, m = INT_MAX, cnt = 0;

void print() {
    int P = 0, Q = 1;
    cnt++;
    for (int i = 1; i <= n; i++)
        if (a[i] == 0) P += b[i-1];
        else Q += b[i];
    if (abs(P - Q)) return;
    m = abs(P - Q);
    cout << "Cau hinh thu " << cnt << "  Tim duoc phuong an phan chia moi, do lech = " << m << endl;
    cout << "P = ";
    for (int i = 1; i <= n; i++)
        if (a[i] == 0) cout << b[i] << " ";
    cout << endl;
    cout << "Q = ";
    for (int i = 1; i <= n; i++)
        if (a[i] == 1) cout << b[i] << " ";
    cout << endl << endl;
}
// sinh giá trị a[k]
void gen(int k) {
    if (k > n) { print(); return; }
    a[k] = 0; gen(k+1);
    a[k] = 1; gen(k+1);
}
int main()
{
    n = sizeof(b)/sizeof(b[0]);
    gen(1);
    return 0;
}
