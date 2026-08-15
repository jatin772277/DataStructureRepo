#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int helper(int i,int n,int k,vector<int>& arr,vector<int>& dp){
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];
    int maxAns = INT_MIN;
    int maxi = INT_MIN;
    int len = 0;
    for(int j = i;j < min(n,i + k);j++){
        len++;
        maxi = max(maxi,arr[j]);
        int sum = (len * maxi) + helper(j+1,n,k,arr,dp);
        maxAns = max(maxAns,sum);
    }
    return dp[i] = maxAns;
}
int PartitionArrayMaxSumMemo(vector<int> arr,int k){
    int n = arr.size();
    vector<int> dp(n,-1);
    return helper(0,n,k,arr,dp);
}
int PartitionArrayMaxSumTabulation(vector<int> arr,int k){
    int n = arr.size();
    vector<int> dp(n+1,0);
    for(int i = n-1;i >= 0;i--){
        int maxAns = INT_MIN,maxi = INT_MIN,len = 0;
        for(int j = i;j < min(n,i+k);j++){
            len++;
            maxi = max(maxi,arr[j]);
            int sum = (len * maxi) + dp[j+1];
            maxAns = max(maxAns,sum);   
        }
        dp[i] = maxAns;
    }
    return dp[0];
}
int main(){
    vector<int> arr = {1,15,7,9,2,5,10};
    cout<<"refer to LeetCode 1043"<<endl;
    int maxi = PartitionArrayMaxSumMemo(arr,3);
    cout<<"Max Sum We can Obtain: "<<maxi<<endl;
    int maxi1 = PartitionArrayMaxSumTabulation(arr,3);
    cout<<"Max Sum We can Obtain: "<<maxi1<<endl;
    return 0;
}