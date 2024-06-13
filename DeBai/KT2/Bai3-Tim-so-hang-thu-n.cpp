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
		cout << "dp[" << i << "] = " << dp[i] << endl;
	}
	return dp[n];
}
int main() {
	cin >> n;
	cout << loop();
}
