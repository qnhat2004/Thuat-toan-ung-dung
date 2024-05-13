#include <bits/stdc++.h>
using namespace std;

const int N = 4;
int a[N] = {0};

void print(int a[]) { 
    for (int i = 0; i < N; i++) cout << a[i];
    cout << '\n';
}
void gen(int i) {
    if (i == N) { print(a); return; }
    a[i] = 0; gen(i+1);
    a[i] = 1; gen(i+1);
}
int main()
{
    gen(0);
    return 0;
}