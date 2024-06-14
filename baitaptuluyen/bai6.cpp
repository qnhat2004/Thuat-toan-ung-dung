#include <bits/stdc++.h>
using namespace std;

int n, k, a[1000], dp[1000][1000];

int gen(int i, int sum) {
	if (sum > k) return 1;
	if (i == n) {
		return 0;
	}
	if (dp[i][sum] != -1) return dp[i][sum];
	return dp[i][sum] = gen(i+1, sum + a[i]) + gen(i+1, sum);
}

// Kinh nghiem debug: neu ra ket qua sai -> doi sang de quy co nho su dung mang dp co so chieu = so tham so cua ham gen

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> k >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << gen(0, 0) << endl;
}
