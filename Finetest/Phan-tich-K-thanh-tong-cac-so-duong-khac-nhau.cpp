#include <bits/stdc++.h>
using namespace std;

int k, dp[1000][100000];

int gen(int i, int sum) {
	if (sum == k) return 1;
	if (i == k) return 0;
	if (dp[i][sum] != -1) return dp[i][sum];
	return dp[i][sum] = gen(i + 1, sum) + gen(i + 1, sum + i);
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cout << "Nhap k = ";
	cin >> k;	
	cout << "Co tat ca " << gen(1, 0) << " cach phan tich.";
	return 0;
}
