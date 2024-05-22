#include <bits/stdc++.h>
using namespace std;

const int N = 9;
int a[N], cnt = 0, b[N];

int tongday() {
    return a[0] + a[1] - a[2] + a[3] - a[4] + a[5] - a[6] + a[7] - a[8];
}

void print() {
    if (tongday() != 23) return;
    cnt++;
    cout << cnt << ": " << a[0];
    for (int i = 1; i < N; i++) cout << (i%2==0 ? "-" : "+") << a[i];
    cout << endl;
}

// Sinh cac hoan vi cua a[k]
void gen(int k) {
    if (k >= N) {
        print();
        return;
    }
    for (int i = k; i < N; i++) {
        if (b[i] == 1) continue;
        a[k] = i+1;
        b[i] = 1;
        gen(k + 1);
        b[i] = 0;
    }
}

int main()
{
    memset(b, 0, sizeof(b));
    clock_t start = clock();
    gen(0);
    clock_t end = clock();
    cout << "cnt = " << cnt;
    cout << "\nTime: " << (double)(end - start) / CLOCKS_PER_SEC << "s";
    return 0;
}
