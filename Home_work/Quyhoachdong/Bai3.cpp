#include <bits/stdc++.h>
using namespace std;

int n, a[30000], dp[30000];

int gen(int i, int last) {
    if (n == i+1) {
        return 0;
    }
    if (dp[i+1] != -1) return dp[i+1];
    int notTake = gen(i+1, last);
    int take = 0;
    if (last == -1 || a[i+1] > a[last])
        take = gen(i+1, i) + 1;
    return dp[i+1] = max(take, notTake);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];  
    cout << gen(-1, -1);  
    return 0;
}