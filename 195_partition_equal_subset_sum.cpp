#include <iostream>
#include <vector>
using namespace std;

bool SubsetSumEqualKTabulation(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
    for (int i = 0; i < n; i++) dp[i][0] = true;
    if (arr[0] <= target) dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= target; j++) {
            bool notTake = dp[i - 1][j];
            bool take = false;
            if (arr[i] <= j) take = dp[i - 1][j - arr[i]];
            dp[i][j] = take || notTake;
        }
    }
    return dp[n - 1][target];
}

bool canPartition(vector<int>& arr, int n) {
    int totSum = 0;
    for(int x : arr) totSum += x;
    if (totSum % 2 != 0) return false;
    return SubsetSumEqualKTabulation(arr, totSum / 2);
}

int main() {
    vector<int> arr = {2, 3, 3, 3, 4, 5};
    int n = arr.size();
    bool canDo = canPartition(arr, n);
    if (canDo) cout << "There are subsets whose sums are equal.\n";
    else cout << "No equal partition exists.\n";
    return 0;
}