#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int a[N], cnt = 0;

void in_ban_co() {
    cout << "Phuong an " << ++cnt << ":\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (a[i] == j ? "H " : "- ");
        }
        cout << endl;
    }
}

bool song_sot(int hang, int cot) {
    for (int i = 0; i < hang; i++) {
        if (cot == a[i]) return false;
        if ((hang - cot) == (i - a[i])) return false;
        if ((hang + cot) == (i + a[i])) return false;
    }
    return true;
}

// Dat quan hau o dong k cot a[k]
void dathau(int k) {
    if (k == N) {
        in_ban_co();
        return;
    }
    for (int i = 0; i < N; i++) {
        if (song_sot(k, i)) {
            a[k] = i;
            dathau(k + 1);
        }
    }
}

int main() {
    dathau(0);
    cout << "Co tat ca " << cnt << " cach dat hau.";
    return 0;
}
