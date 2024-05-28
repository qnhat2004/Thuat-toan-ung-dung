#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Nhap N = ";
    cin >> n;
    int a[10] = {0}, i = 9;
    while(n > 1 && i > 1) {
        while(n % i == 0) {
            a[i]++;
            n /= i;
        }
        i--;
    }
    if (n == 0)
        cout << "K = " << 10;
    else if (n != 1) 
        cout << "NO";
    else {
        cout << "K = ";
        for (int i = 2; i <= 9; i++) {
            for (int j = 0; j < a[i]; j++) {
                cout << i;
            }
        }
    }
    return 0;
}