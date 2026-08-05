#include<iostream>
#include<vector>
using namespace std;
int helper(int i,int j,string& str1,string& str2,vector<vector<int>>& dp){
    if(i < 0 && j < 0) return 1;
    if(i < 0 && j >= 0) return 0;
    if(j < 0 && i >= 0){
        for(int k = 0;k <= i;k++) if(str1[k] != '*') return 0;
        return 1;
    }
    if(dp[i][j] != -1) return dp[i][j];
    if((str1[i] == str2[j]) || str1[i] == '?') return dp[i][j] = helper(i-1,j-1,str1,str2,dp);
    if(str1[i] == '*') return dp[i][j] = (helper(i-1,j,str1,str2,dp) || helper(i,j-1,str1,str2,dp));
    return dp[i][j] = 0;
}
int WildCardMatchingMemo(string& str1,string& str2){
    int n1 = str1.size();
    int n2 = str2.size();
    vector<vector<int>> dp(n1,vector<int>(n2,-1));
    return helper(n1-1,n2-1,str1,str2,dp);
}
int WildCardMatchingTabulation(string& str1,string& str2){
    int n1 = str1.size(),n2 = str2.size();
    vector<vector<int>> dp(n1+1,vector<int>(n2 +1,0));
    dp[0][0] = 1;
    dp[0][0] = 1;
    for(int i = 1; i <= n1; i++) dp[i][0] = (str1[i-1] == '*') && dp[i-1][0];
    for(int i = 1;i <= n1;i++){
        for(int j = 1;j <= n2;j++){
            if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1];
            else if(str1[i-1] == '*' || str1[i-1] == '?') dp[i][j] = dp[i-1][j] || dp[i][j-1];
            else dp[i][j] = 0;
        }
    }
    return dp[n1][n2];
}
int main(){
    string str1 = "ab*cd";
    string str2 = "abdefcd";
    string str3 = "**abcd";
    string str4 = "abcd";
    string str5 = "ab?d";
    string str6 = "abcc";
    bool true1 = WildCardMatchingMemo(str1,str2);
    bool true2 = WildCardMatchingMemo(str3,str4);
    bool true3 = WildCardMatchingMemo(str5,str6);
    if(true1) cout<<"str1 and str2 are Matching!!"<<endl;
    else cout<<"Not Matching(str1 and str2)"<<endl;
    if(true2) cout<<"str3 and str4 are Matching!!"<<endl;
    else cout<<"Not Matching(str3 and str4)"<<endl;
    if(true3) cout<<"str5 and str6 are Matching!!"<<endl;
    else cout<<"Not Matching(str5 and str6)"<<endl;
    true1 = WildCardMatchingTabulation(str1,str2);
    true2 = WildCardMatchingTabulation(str3,str4);
    true3 = WildCardMatchingTabulation(str5,str6);
    if(true1) cout<<"str1 and str2 are Matching!!"<<endl;
    else cout<<"Not Matching(str1 and str2)"<<endl;
    if(true2) cout<<"str3 and str4 are Matching!!"<<endl;
    else cout<<"Not Matching(str3 and str4)"<<endl;
    if(true3) cout<<"str5 and str6 are Matching!!"<<endl;
    else cout<<"Not Matching(str5 and str6)"<<endl;
    return 0;
}