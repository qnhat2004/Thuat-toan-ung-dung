#include <bits/stdc++.h>
using namespace std;

int n, dp[30000], a[30000];

int gen(int i, int last) {
	if (i == n) {
		return 0;
	}
	if (dp[i] != -1) return dp[i];
	if (last < a[i]) return dp[i] = max(gen(i+1, i) + 1, gen(i+1, last));
	return dp[i] = gen(i+1, last);
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << gen(0, -1);
}    
