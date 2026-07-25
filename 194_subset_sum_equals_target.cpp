#include<iostream>
#include<vector>
using namespace std;
bool helper(int n,int target,vector<int>& arr,vector<vector<int>>& dp){
    if(target == 0) return true;
    if(n == 0) return (arr[0] == target);
    if(dp[n][target] != -1) return dp[n][target];
    bool notTake = helper(n-1,target,arr,dp);
    bool take = false;
    if(target >= arr[n]) take = helper(n-1,target-arr[n],arr,dp);
    return dp[n][target] = take || notTake;
}
bool SubsetSumEqualKMemo(vector<int>& arr,int target){
    vector<vector<int>> dp(arr.size(),vector<int>(target+1,-1));
    return helper(arr.size()-1,target,arr,dp);
}
bool SubsetSumEqualKTabulation(vector<int>& arr,int target){
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    for(int i = 0;i < n;i++) dp[i][0] = true;
    if(arr[0] <= target) dp[0][arr[0]] = true;
    for(int i = 1;i < n;i++){
        for(int j = 1;j <= target;j++){
            bool notTake = dp[i-1][j];
            bool take = false;
            if(arr[i] <= j) take = dp[i-1][j - arr[i]];
            dp[i][j] = notTake || take;
        }
    }
    return dp[n-1][target];
}
int main(){
    vector<int> arr = {1,2,1,3,5,8,3,7};
    int target = 14;
    bool isExistSubset = SubsetSumEqualKMemo(arr,target);
    if(isExistSubset) cout<<"there exists a subset whose sum is "<<target<<"."<<endl;
    else cout<<"Doesn't Exist!!"<<endl;
    bool isExistSubset1 = SubsetSumEqualKTabulation(arr,target);
    if(isExistSubset1) cout<<"there exists a subset whose sum is "<<target<<"."<<endl;
    else cout<<"Doesn't Exist!!"<<endl;
    return 0;
}