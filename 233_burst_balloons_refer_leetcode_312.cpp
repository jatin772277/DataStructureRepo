#include<iostream>
#include<vector>
using namespace std;
int helper(int i,int j,vector<int>& arr,vector<vector<int>>& dp){
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int maxi = -1e8;
    for(int ind = i;ind <= j;ind++){
        int cost = arr[i-1] * arr[j + 1] * arr[ind] + helper(i,ind-1,arr,dp) + helper(ind+1,j,arr,dp);
        maxi = max(maxi,cost);
    }
    return dp[i][j] = maxi;
}
int BurstBalloonsMemo(vector<int> arr){
    arr.insert(arr.begin(),1);
    arr.push_back(1);
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return helper(1,n-2,arr,dp);
}
int BurstBalloonsTabulation(vector<int> arr){
    arr.insert(arr.begin(),1);
    arr.push_back(1);
    int n = arr.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i = n;i >= 1;i--){
        for(int j = 1;j <= n-2;j++){
            if(i > j) continue;
            int maxi = -1e8;
            for(int ind = i;ind <= j;ind++){
                int cost = arr[i-1] * arr[j+1] * arr[ind] + dp[i][ind-1] + dp[ind+1][j];
                maxi = max(maxi,cost);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n-2];
}
int main(){
    vector<int> balloons = {3,1,5,8};
    int maxPoints = BurstBalloonsMemo(balloons);
    cout<<"Points will be incremented if Balloon bursted!!"<<endl;
    cout<<"Max Points: "<<maxPoints<<endl;
    int maxPoints1 = BurstBalloonsTabulation(balloons);
    cout<<"Points will be incremented if Balloon bursted!!"<<endl;
    cout<<"Max Points: "<<maxPoints1<<endl;
    return 0;
}