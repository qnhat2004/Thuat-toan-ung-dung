#include <bits/stdc++.h>
using namespace std;

int dem = 0;

// sinh buoc chuyen n dia tu coc A sang coc C, dung coc B la trung gian
void chuyen(int n, char A, char B, char C) {
    dem++;
    if (n > 1) chuyen(n-1, A, C, B); // chuyen n-1 dia tu coc A sang coc B, dung coc C la trung gian
    cout << "Chuyen tu " << A << " sang " << C << endl; // chuyen 1 dia thu n tu coc A sang coc C
    if (n > 1) chuyen(n-1, B, A, C); // chuyen n-1 dia tu coc B sang coc C, dung coc A la trung gian
}

int main()
{
    chuyen(4, 'A', 'B', 'C');
    cout << "So buoc chuyen: " << dem;
    return 0;
}