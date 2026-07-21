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

    int rob1(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(n - 1, nums, dp);
    }
    int rob(vector<int>& nums){
        if(nums.size() == 1) return nums[0];
        vector<int> arr(nums.begin() + 1,nums.end());
        nums.pop_back();
        int a = rob1(arr),b = rob1(nums);
        return max(a,b);
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3};
    cout<<"Answer = "<<s.rob(nums)<<endl;
    return 0;
}