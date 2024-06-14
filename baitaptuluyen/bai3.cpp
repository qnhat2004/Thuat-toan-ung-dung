#include <bits/stdc++.h>
using namespace std;

#define ll long long 

ll n, dp[10000];

ll gen(ll k) {
	if (k == 0) return 1;
	if (k < 0) return 0;
	if (dp[k] != -1) return dp[k];
	return dp[k] = gen(k-2) + gen(k-3);
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	cout << gen(n);
}
