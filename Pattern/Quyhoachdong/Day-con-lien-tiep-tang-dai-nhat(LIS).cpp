#include <bits/stdc++.h>
using namespace std;

// O(n^2)
int useDP(vector<int> &nums) {
	vector<int> dp(nums.size(), 1);
	dp[0] = 1;
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (nums[i] > nums[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	return dp[nums.size()-1];
} 

// O(nlogn)
int useDP2(vector<int> &nums)
{
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int len = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < dp[0])
        {
            dp[0] = nums[i];
        }
        else if (nums[i] > dp[len - 1])
        {
            dp[len++] = nums[i];
        }
        else
        {
            int l = 0, r = len - 1;
            while (l < r)
            {
                int m = l + (r - l) / 2;
                if (dp[m] < nums[i])
                {
                    l = m + 1;
                }
                else
                {
                    r = m;
                }
            }
            dp[r] = nums[i];
        }
    }
    return len;
}

// O(nlogn)
int useBinarySearch(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    ans.push_back(nums[0]);
    for (int i = 1; i < n; i++)
    {
        //		cout << "ans: "; for (int j = 0; j < ans.size(); j++) cout << " " << ans[j]; cout << endl; // DEBUG
        if (nums[i] > ans.back()) // Neu nums[i] lon hon phan tu cuoi cung tuc la phan tu lon nhat cua mang, nghia la co the keo dai day con tang dan
            ans.push_back(nums[i]);
        else
        {
            int low = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin(); // Tim kiem index phan tu dau tien >= nums[i]
            ans[low] = nums[i];                                                   // Thay the gia tri phan tu tai index voi y nghia day con sau khi thay co tiem nang hon vi ta thay phan tu lon bang phan tu nho, nghia la trong tuong lai co the gap nhieu phan tu phu hop hon
        }
    }
    return ans.size();
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    cout << "DP: " << useDP(nums) << endl;
    cout << "DP + binary search: O(nlogn): " << useDP2(nums) << endl;
    cout << "Binary search O(nlogn): " << useBinarySearch(nums) << endl;
    return 0;
}
