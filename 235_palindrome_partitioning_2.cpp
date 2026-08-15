#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;
bool isPalindrome(string& str){
    int i = 0,j = str.size()-1;
    while(i < j){
        if(str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}
int helper(int i,int n,string& str,vector<int>& dp){
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];
    string temp = "";
    int minCost = INT_MAX;
    for(int j = i;j < n;j++){
        temp += str[j];
        if(isPalindrome(temp)){
            int cost = 1 + helper(j+1,n,str,dp);
            minCost = min(minCost,cost);
        }
    }
    return dp[i] = minCost;
}
int PalindromePartition2Memo(string str){
    int n = str.size();
    vector<int> dp(n,-1);
    return helper(0,n,str,dp);
}
int PalindromePartition2Tabulation(string str){
    int n = str.size();
    vector<int> dp(n+1,0);
    dp[n] = 0;
    for(int i = n - 1;i >= 0;i--){
        int minCost = INT_MAX;
        string temp = "";
        for(int j = i;j < n;j++){
            temp += str[j];
            if(isPalindrome(temp)){
                int cost = 1 + dp[j+1];
                minCost = min(minCost,cost);
            }
        }
        dp[i] = minCost;
    }
    return dp[0];
}
int main(){
    string str = "bababcbadeede";
    cout<<"Refer to the leetcode 132"<<endl;
    int minPartition = PalindromePartition2Memo(str);
    cout<<"Minimum Partition: "<<minPartition<<endl;
    int minPartition1 = PalindromePartition2Tabulation(str);
    cout<<"Minimum Partition: "<<minPartition1<<endl;
    return 0;
}