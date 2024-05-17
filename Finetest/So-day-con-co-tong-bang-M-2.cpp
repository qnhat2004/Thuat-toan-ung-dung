#include<bits/stdc++.h>
using namespace std;

int m, n, cnt = 0, dp[100][100000], a[100];

void gen(int i, int sum) {
	if (sum == m || dp[i][sum] == 1) {
		cnt++;
		dp[i][sum] = 1;
		return;
	}
	if (i == n || sum > m || dp[i][sum] != -1) return;
	dp[i][sum] = 0;
	gen(i+1, sum);
	gen(i+1, sum + a[i]);
}
int main(){
    cout << "Nhap m = "; cin >> m;
    cout << "Nhap n = "; cin >> n;
    for (int i = 0; i < n; ++i) {
        printf("a[%d] = ", i);
        cin >> a[i];
    }
	memset(dp, -1, sizeof(dp));    
    gen(0, 0);
    cout << "Co tat ca " << cnt << " cach phan tich.";
	return 0;
}

