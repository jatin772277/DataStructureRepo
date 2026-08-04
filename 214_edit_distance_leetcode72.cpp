#include<iostream>
#include<vector>
using namespace std;
int helper(int i,int j,string& str1,string& str2,vector<vector<int>>& dp){
    if(i < 0) return j + 1;
    if(j < 0) return i + 1;
    if(dp[i][j] != -1) return dp[i][j];
    if(str1[i] == str2[j]) return dp[i][j] = helper(i-1,j-1,str1,str2,dp);
    int insert = 1 + helper(i,j-1,str1,str2,dp);
    int deleteO = 1 + helper(i-1,j,str1,str2,dp);
    int replace = 1 + helper(i-1,j-1,str1,str2,dp);
    return dp[i][j] = min(insert,min(deleteO,replace));
}
int EditDistanceMemo(string& str1,string& str2){
    int n = str1.size(),m = str2.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return helper(n-1,m-1,str1,str2,dp);
}
int EditDistanceTabulation(string& str1,string& str2){
    int n1 = str1.size(),n2 = str2.size();
    vector<vector<int>> dp(n1 +1,vector<int>(n2+1,0));
    for(int i = 0;i <= n1;i++) dp[i][0] = i;
    for(int j = 0;j <= n2;j++) dp[0][j] = j;
    for(int i = 1;i <= n1;i++){
        for(int j = 1;j <= n2;j++){
            if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
                int insert = 1 + dp[i][j-1];
                int deleteO = 1 + dp[i-1][j];
                int replace = 1 + dp[i-1][j-1];
                dp[i][j] = min(insert,min(deleteO,replace));
            }
        }
    }
    return dp[n1][n2];
}
int main(){
    string str1 = "intention";
    string str2 = "execution";
    int minOper = EditDistanceMemo(str1,str2);
    cout<<"We can Delete any char,we can add any char ,we can replace any char unlimited time."<<endl;
    cout<<"return Min Operation to Convert str1 to str2"<<endl;
    cout<<"Min Operation: "<<minOper<<endl;
    int minOper1 = EditDistanceTabulation(str1,str2);
    cout<<"Min Operation: "<<minOper1<<endl;
    return 0;
}