#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = nums.size();
    int dp[n];
    dp[0] = nums[0];
    int mx, prev;
    mx = prev = nums[0];
    int l = 0, r = 0, tmp_l = 0;
    for (int i = 1; i < n; i++) {
        if (nums[i] > prev + nums[i]) { // Bat dai 1 day con moi
            tmp_l = i;
        }
        prev = max(prev + nums[i], nums[i]);
        if (prev > mx) {
            l = tmp_l;
            r = i;
        }
        mx = max(mx, prev);
    }
    cout << mx << endl;
    cout << l << " " <<  r << endl;
    return 0;
}