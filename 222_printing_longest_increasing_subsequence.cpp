#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> PrintLongestIncreasingSubsequence(vector<int>& arr){
    int n = arr.size();
    vector<int> dp(n,1),hash(n);
    int maxi = 1;
    int lastIndex = 0;
    for(int i = 0;i < n;i++){
        hash[i] = i;
        for(int prev = 0;prev < i;prev++){
            if(arr[prev] < arr[i] && 1 + dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(),temp.end());
    return temp;
}
int main(){
    vector<int> arr = {10,9,2,5,3,7,101,18};
    vector<int> increasingSubsequence = PrintLongestIncreasingSubsequence(arr);
    cout<<"Sequence : "<<endl;
    for(int x : increasingSubsequence) cout<<x<<" ";
    cout<<endl;
    return 0;
}