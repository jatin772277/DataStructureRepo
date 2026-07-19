#include<iostream>
#include<vector>
using namespace std;
int FibonacciDP(int term,vector<int> &dp){//Memoization
    if(term == 0 || term == 1) return dp[term] = term;
    if(dp[term] != -1) return dp[term];
    else{
        dp[term] = FibonacciDP(term - 1,dp) + FibonacciDP(term - 2,dp);
    }
    return dp[term];
}
// int FibonacciDP(int term,vector<int> &dp){//Tabulation
//     dp[0] = 0;
//     dp[1] = 1;
//     for(int i = 2;i <= term;i++) dp[i] = dp[i-1] + dp[i-2];
//     return dp[term];
// }
// int FibonacciDP(int term,vector<int>& dp){//Optimization
//     int prev2 = 0,prev1 = 1;
//     int curr;
//     for(int i = 2;i <= term;i++){
//         curr = prev2 + prev1;
//         prev2 = prev1;
//         prev1 = curr;
//     }
//     return curr;
// }
int main(){
    int term;
    cout<<"Enter The Term of Fibonacci Series You want: ";
    cin>>term;
    vector<int> dp(term + 1,-1);
    int fib = FibonacciDP(term,dp);
    cout<<"Term is: "<<fib<<endl;
    return 0;
}