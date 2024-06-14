#include <bits/stdc++.h>
using namespace std;

#define ll long long 
const ll mod = 1e9 + 7;
ll n, dp[100005];

ll cong(const ll &a, const ll &b) {
	ll result = a + b;
	if (result > mod) return result - mod;
	return result; 
}

ll gen(ll k) {
	if (k == 0) return 1;
	if (k < 0) return 0;
	if (dp[k] != -1) return dp[k];
	dp[k] = 0ll;
	for (int i = 2; i <= 4; i++) {
		dp[k] = cong(dp[k], gen(k - i));
	}
	return dp[k];
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	cout << gen(n);
}
