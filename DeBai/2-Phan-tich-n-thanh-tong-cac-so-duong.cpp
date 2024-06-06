#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<int, int> dp;
int dp2[200][100000];

int gen(int i, int sz, int last) {
    if (i == 0) {
    	if (sz > 1) return 1;
		return 0; 
	}
    int key = i*1000 + last;
	if (dp.count(key)) return dp[key];
	dp[key] = 0;
	for (int j = min(i, last); j >= 1; j--) {
		dp[key] += gen(i-j, sz+1, j);
	}
	return dp[key];
}

int main()
{
	// memset(dp, -1, sizeof(dp));
    cout << "nhap n\n";
    cin >> n;
	cout << "So kieu phan tich la: " << gen(n, 0, n);
    return 0;
}
