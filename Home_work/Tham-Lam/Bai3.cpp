#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Nhap N = ";
    cin >> n;
    string s = "";
    for (int i = 9; i > 1 && n > 1; i--)
    {
        while (n % i == 0)
        {
            s = to_string(i) + s; // or s = char(i + '0) + s;
            n /= i;
        }
    }
    if (n == 1)
        cout << "K = " << s;
    else
        cout << "NO";
    return 0;
}