#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int helper(int index, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        if(index >= days.size()) return 0;

        int n = days.size();

        if(dp[index] != -1) return dp[index];

        int i = index;
        while(i < n && days[i] < days[index] + 1) i++;
        int oneDay = costs[0] + helper(i, days, costs, dp);

        i = index;
        while(i < n && days[i] < days[index] + 7) i++;
        int sevenDay = costs[1] + helper(i, days, costs, dp);

        i = index;
        while(i < n && days[i] < days[index] + 30) i++;
        int thirtyDay = costs[2] + helper(i, days, costs, dp);

        return dp[index] = min(oneDay, min(sevenDay, thirtyDay));
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return helper(0, days, costs, dp);
    }
};

int main() {
    Solution obj;

    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};

    cout << obj.mincostTickets(days, costs) << endl;

    return 0;
}