#include <bits/stdc++.h>
using namespace std;

const int S = 7;
const int N = 3;
int a[S] = {1, 7, 6, 3, 3};
int dp[1000][1000];

int gen(int i, int sum) { // top-down
    if (i == N) {
        if (sum == S) return 1;
        return 0;
    }
    if (dp[i][sum] != -1) return dp[i][sum];
    return dp[i][sum] = gen(i+1, sum) + (sum + a[i] <= S ? gen(i+1, sum + a[i]) : 0); // So cach tao ra tong sum tu i phan tu dau tien
}

int gen1(int i, int sum) {
    if (i == 0) {
        if (sum == 0) return 1;
        return 0;
    }
    if (dp[i][sum] != -1) return dp[i][sum];
    if (sum < a[i-1]) return gen1(i-1, sum);
	return gen1(i-1, sum) + gen(i-1, sum-a[i-1]);
}

int QHD() { // bottom-up
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= S; j++) {
            if (i == 0) dp[i][j] = (j == 0 ? 1 : 0); // Neu i = 0, j = 0 nghia la co 1 cach tao ra tong bang 0 tu 0 phan tu, nguoc lai neu j != 0 nghia la co 0 cach tao ra tong j tu 0 phan tu dau tien
            else dp[i][j] = dp[i-1][j] + (j >= a[i-1] ? dp[i-1][j-a[i-1]] : 0); 
        }
    }
    return dp[N][S];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cout << "De quy co nho: " << gen(0, 0) << endl;   
    cout << "Quy hoach dong: " << QHD() << endl; 
    cout << "Top-down: " << gen1(N, S) << endl;
    return 0;
}
