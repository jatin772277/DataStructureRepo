#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int helper(int index, vector<int>& nums, vector<int>& dp) {
        if (index == 0) return dp[0] = nums[0];
        if (index < 0) return 0;

        if (dp[index] != -1) return dp[index];

        int pick = nums[index] + helper(index - 2, nums, dp);
        int nonpick = helper(index - 1, nums, dp);

        return dp[index] = max(pick, nonpick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(n - 1, nums, dp);
    }
};

int main() {
    Solution s;

    vector<int> nums = {2, 7, 9, 3, 1};

    cout << "Answer = " << s.rob(nums) << endl;

    return 0;
}