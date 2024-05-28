#include <bits/stdc++.h>
using namespace std;

int n, a[100];

bool dk1() {
    int chan = 0, le = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) chan++;
        else le++;
    }
    return chan > le;
}
bool dk2() {
    for (int i = 0; i < n; i++) 
        if (a[i] % 5 == 0) return true;
    return false;
}
bool dk3() {
    for (int i = 0; i < n-1; i++) 
        for (int j = i+1; j < n; j++) {
            if (a[i]*a[j] % 8 == 0)
                return true;
        }
    return false;
}
bool dk4() {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (a[i] > 13) cnt++;
    return cnt <= 3;
}
void print() {
    if (!dk1()) return;
    if (!dk2()) return;
    if (!dk3()) return;
     
}

void gen(int i) {
    if (i >= n) { print(); return; }
    for (int j = 0; j <= 1; j++) {
        a[i] = j;
        gen(i+1);
    }
}

int main()
{
    
    return 0;
}