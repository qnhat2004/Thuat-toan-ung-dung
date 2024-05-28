#include <bits/stdc++.h>
using namespace std;

int k, a[100], cnt = 0, ready[100], dp[100] = {-1}; // dp[i]: so cach phan tich i thanh tong cua cac so duong khac nhau

void print(int sz) {
	cout << cnt << ": ";
	cout << a[0];
	for (int i = 1; i < sz; i++)
		cout << "+" << a[i];
	cout << endl;
}

int gen(int cur, int sz, int sum, int last = 1e6) {
	if (dp[cur] != -1) return dp[cur];
	if (cur == 0) {
		if (sz > 1) {
			cnt++;
			// print(sz);
			dp[cur] = 1;
		}
		return 1;
	}
	dp[cur] = 0;
	for (int i = min(cur, last); i >= 1; i--)
	{
		if (ready[i]) {
			continue;
		}
		if (dp[i] == -1) {
			last = i;
			a[sz] = i;
			ready[i] = 1;
			dp[cur] += gen(cur - i, sz + 1, i);
			ready[i] = 0;
		}
		else {
			dp[cur] += dp[i];
		}
	}
	return dp[cur];
}

int main()
{
	cout << "Nhap k = ";
	cin >> k;
	cout << "Co tat ca " << gen(k, 0, 0) << " cach phan tich.";
	return 0;
}
