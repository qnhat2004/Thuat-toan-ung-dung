#include <bits/stdc++.h>
using namespace std;

// O(n)
int maxSubsequence(vector<int> &nums)
{
    int mx, prev;
    mx = prev = nums[0];
    int l = 0, r = 0, tmp_l = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > prev + nums[i])
        { // Bat dai 1 day con moi
            tmp_l = i;
        }
        prev = max(prev + nums[i], nums[i]);
        if (prev > mx)
        {
            l = tmp_l;
            r = i;
        }
        mx = max(mx, prev);
    }
    cout << "from " << l << " to " << r << endl; // In doan con lon nhat
    return mx;
}

int main()
{
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++ ) cin >> nums[i];
    cout << maxSubsequence(nums) << endl;
    return 0;
}
