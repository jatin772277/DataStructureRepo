#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int helper(int index,vector<int>& heights,int k,vector<int>& dp){
    if(index == 0) return dp[0] = 0;
    if(dp[index] != -1) return dp[index];
    int minEnergy = INT_MAX;
    for(int j = 1;j <= k;j++){
        if(index - j >= 0){
            int jump = helper(index - j,heights,k,dp) + abs(heights[index] - heights[index-j]);
            minEnergy = min(minEnergy , jump);
        }
    }
    return dp[index] = minEnergy;
}
int FrogJumpKDistance(vector<int>& heights,int k){
    int n = heights.size();
    vector<int> dp(n+1,-1);
    return helper(n-1,heights,k,dp);
}
int main(){
    vector<int> heights = {10, 30, 40, 20, 25};
    int k = 3;
    cout<<"Minimum Energy = "<< FrogJumpKDistance(heights, k) << endl;
    return 0;

}