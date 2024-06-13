#include <bits/stdc++.h>
using namespace std;

int n, dp[1000];

// Cach 1: dung vong lap
int loop() {
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = 0;
		for (int j = i; j >= 1; j--) {
			dp[i] += j*j * dp[i-j];
		}
//		cout << "dp[" << i << "] = " << dp[i] << endl;
	}
	return dp[n];
}

// Cach 2: dung de quy co nho
int rec(int i) {
    if (i == 0) return 1;
    if (dp[i] != 0) return dp[i];
    for (int j = i; j >= 1; j--) {
    	dp[i] += j*j * rec(i-j);
	}
	return dp[i];
}

int main() {
	cin >> n;
	cout << loop() << endl;
    memset(dp, 0, sizeof(dp));
    cout << rec(n) << endl;
}
