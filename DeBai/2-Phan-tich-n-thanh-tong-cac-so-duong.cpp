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
	if (dp2[i][last] != -1)
        return dp2[i][last];
	dp2[i][last] = 0;
	for (int j = min(i, last); j >= 1; j--) {
		dp2[i][last] += gen(i-j, sz+1, j);
	}
	return dp2[i][last];
}

int main()
{
	memset(dp2, -1, sizeof(dp2));
    cout << "nhap n\n";
    cin >> n;
	cout << "So kieu phan tich la: " << gen(n, 0, n);
    return 0;
}
