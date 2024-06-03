#include <bits/stdc++.h>
using namespace std;

const int M = 6;
const int N = 7;

int a[M] = {3, 1, 2, 0, 4, 3};
int b[N] = {3, 1, 2, 0, 4, 3, 5};

int s(int m, int n) // top-down
{
    if (m == 0 || n == 0)
        return 0;
    if (a[m - 1] == b[n - 1])
        return 1 + s(m - 1, n - 1);
    return max(s(m - 1, n), s(m, n - 1));
}

int dp[1000][1000];
int QHD(int m, int n) // bottom-up
{
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    return dp[m][n];
}

int main()
{
    cout << "Do dai max (de quy) = " << s(M, N) << endl;
    cout << "Do dai max (QHD): " << QHD(M, N) << endl;
    return 0;
}