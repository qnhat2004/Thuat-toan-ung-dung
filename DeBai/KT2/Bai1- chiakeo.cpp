#include <bits/stdc++.h>
using namespace std;

int n, a[1000], total = 0, dp[1000][100000];

int gen(int i, int sum) {
	if (i == n) {
		return abs(total - 2*sum);
	}
	if (dp[i][sum] != -1) return dp[i][sum];	
	return dp[i][sum] = min(gen(i+1, sum+a[i]), gen(i+1, sum));
}

int main() {
	memset(dp, -1, sizeof(dp));	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		total += a[i];
	}
	cout << gen(0, 0);
}

/* input:
11
1 2 3 4 5 8 7 7 10 20 1
*/
