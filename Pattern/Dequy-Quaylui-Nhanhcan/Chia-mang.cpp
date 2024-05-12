#include <bits/stdc++.h>
using namespace std;

const int N = 130;
int a[N];

void init(int a[]) {
   for (int i = 0; i < N; i++) a[i] = rand();
}

// Cach 1: De quy
int minPartition(int a[], int n, int i, int sum, int total) {
    if (i >= n) {
        return abs(total - 2*sum);
    }
    return min(minPartition(a, n, i+1, sum + a[i], total), minPartition(a, n, i+1, sum, total));
}

// Cach 2: 
int minPartition2(int a[], int n, int i, int sum, int total, vector<vector<int>> &dp) {
    if (i >= n) return abs(total - 2*sum);
    if (dp[i][sum] != -1) return dp[i][sum];
    return dp[i][sum] = min(minPartition2(a, n, i+1, sum + a[i], total, dp), minPartition2(a, n, i+1, sum, total, dp));
}

int main()
{
    clock_t start;

    init(a);
    // int n; cin >> n;
    // int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

    start = clock();
    cout << minPartition(a, N, 0, 0, accumulate(a, a+N, 0)) << '\n';    
    cout << "Time backtrack: " << (clock() - start) / (double)(CLOCKS_PER_SEC) << '\n';

    start = clock();
	cout << minPartition(a, N, 0, 0, accumulate(a, a+N, 0)) << '\n';
	cout << "Time dp: " << (clock() - start) / (double)(CLOCKS_PER_SEC) << '\n';    
    return 0;
}
