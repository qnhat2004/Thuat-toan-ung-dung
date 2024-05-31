#include <bits/stdc++.h>
using namespace std;

int n, a[100], total = 0, min_diff = 1e9;

void gen(int i, int sum) {
    if (i >= n) {
        min_diff = min(min_diff, abs(total - 2*sum));
        return;
    }
    gen(i + 1, sum + a[i]);
    gen(i + 1, sum);
}

int main()
{
    cout << "Nhap n = ";
    cin >> n;       
    cout << "Nhap mang A: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }
    gen(0, 0);
    cout << "Chenh lech so vien keo giua 2 phan la it nhat: " << min_diff;
    return 0;
}