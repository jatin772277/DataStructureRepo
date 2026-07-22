#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int helper(int day, int last, vector<vector<int>>& points,
               vector<vector<int>>& dp) {

        if (dp[day][last] != -1)
            return dp[day][last];

        if (day == 0) {
            int maxi = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last)
                    maxi = max(maxi, points[0][task]);
            }
            return dp[day][last] = maxi;
        }

        int maxi = 0;

        for (int task = 0; task < 3; task++) {
            if (task != last) {
                maxi = max(maxi,
                           points[day][task] +
                           helper(day - 1, task, points, dp));
            }
        }

        return dp[day][last] = maxi;
    }

    int ninjaTraining(int n, vector<vector<int>> &points) {
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return helper(n - 1, 3, points, dp);
    }
};
int main(){
    vector<vector<int>> arr = {
        {2,1,3},
        {3,4,6},
        {10,1,6},
        {8,3,7}
    };
    Solution obj;
    int a = obj.ninjaTraining(4,arr);
    cout<<"Max Gain: "<<a<<endl;
    return 0;
}