#include <iostream>
#include <vector>
#include <numeric>
#include <climits>
using namespace std;
bool helper(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (ind == 0) return arr[0] == target;
    if (dp[ind][target] != -1) return dp[ind][target];
    bool notTake = helper(ind - 1, target, arr, dp);
    bool take = false;
    if (arr[ind] <= target) take = helper(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = take || notTake;
}
int minimumDifferenceMemo(vector<int>& arr) {
    int n = arr.size();
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));
    int mini = INT_MAX;
    for (int s1 = 0; s1 <= totalSum / 2; s1++) {
        if (helper(n - 1, s1, arr, dp)) mini = min(mini, totalSum - 2 * s1);
    }
    return mini;
}

int minimumDifferenceTabulation(vector<int>& arr) {
    int n = arr.size();
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));
    for (int i = 0; i < n; i++) dp[i][0] = true;
    if (arr[0] <= totalSum) dp[0][arr[0]] = true;
    for (int ind = 1; ind < n; ind++) {
        for (int target = 1; target <= totalSum; target++) {
            bool notTake = dp[ind - 1][target];
            bool take = false;
            if (arr[ind] <= target) take = dp[ind - 1][target - arr[ind]];
            dp[ind][target] = take || notTake;
        }
    }
    int mini = INT_MAX;
    for (int s1 = 0; s1 <= totalSum / 2; s1++) {
        if (dp[n - 1][s1]) mini = min(mini, totalSum - 2 * s1);
    }
    return mini;
}
int main() {
    vector<int> arr = {2, 2, 3, 4};
    cout<<minimumDifferenceMemo(arr)<<endl;
    cout<<minimumDifferenceTabulation(arr)<<endl;
    return 0;
}