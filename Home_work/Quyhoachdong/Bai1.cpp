#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int a[N], dp[N], dp1[N][N];

void init() {
	memset(dp1, -1, sizeof(dp1));
    for (int i = 0; i < N; i++) dp[i] = 1;
    for (int i = 0; i < N; i++) a[i] = rand() % 100;
}

// De quy co nho
int gen(int i, int last) { // last index
    if (i == N) {
        return 0;
    }
    if (dp1[i][last+1] != -1) return dp1[i][last+1];
    int notTake = gen(i+1, last);
    int take = 0;
    if (last == -1 || a[i] >= a[last])
        take = gen(i+1, i) + 1;
    return dp1[i][last+1] = max(notTake, take);
}

// Quy hoach dong
int qhd() {
	int ans = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] >= a[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
				ans = max(ans, dp[i]);
			}
		}
	}
	return ans; 
}

int main()
{
    init();
    for (int i = 0; i < N; i++) cout << a[i] << " "; cout << endl;
    cout << "De quy co nho: " << gen(0, -1) << endl;
    cout << "Quy hoach dong: " << qhd() << endl;
    return 0;
}
