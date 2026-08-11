#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> LargestDivisibleSubset(vector<int>& arr){
    int n = arr.size();
    sort(arr.begin(),arr.end());
    vector<int> dp(n,1),hash(n);
    int maxi = 1,lastIndex = 0;
    for(int i = 0;i < n;i++){
        hash[i] = i;
        for(int j = 0;j < i;j++){
            if(arr[i] % arr[j] == 0 && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                hash[i] = j;
            }
        }
        if(maxi < dp[i]){
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
    vector<int> arr = {1,16,7,8,4};
    vector<int> sett = LargestDivisibleSubset(arr);
    cout<<"LDS : any pair is divisible like: arr[i] % arr[j] == 0 or Reverse of it!!"<<endl;
    cout<<"LDS: ";
    for(int x : sett) cout<<x<<" ";
    cout<<endl;
    return 0;
}