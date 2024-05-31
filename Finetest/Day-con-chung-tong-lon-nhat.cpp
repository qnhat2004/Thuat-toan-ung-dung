#include <bits/stdc++.h>
using namespace std;

int m, n, a[1000], b[1000];
int dp[1000][1000];

int gen(int i, int j)
{
    if (i == m || j == n)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i] == b[j])
        return dp[i][j] = gen(i + 1, j + 1) + a[i];
    return dp[i][j] = max(gen(i + 1, j), gen(i, j + 1));
}

int main()
{
    cout << "Nhap m = ";
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cout << "a[" << i + 1 << "] = ";
        cin >> a[i];
    }
    cout << "Nhap n = ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "b[" << i + 1 << "] = ";
        cin >> b[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << "Day con co tong lon nhat = " << gen(0, 0);
}
