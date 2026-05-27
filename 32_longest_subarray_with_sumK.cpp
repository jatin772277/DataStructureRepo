#include<iostream>
#include<vector>
#include<map>
using namespace std;

int LongestSubarraySumK(vector<int> &arr,int k){
    map<int,int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for(int i = 0;i < arr.size();i++){
        sum += arr[i];
        if(sum == k) maxLen = max(maxLen , i + 1);
        int rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem];
            maxLen = max(maxLen , len);
        }
        if(preSumMap.find(sum) == preSumMap.end()) preSumMap[sum] = i;
    }
    return maxLen;
}
int main(){
    vector<int> arr = {2, 3, 5, -5, 8, -3, 2};
    int k = 10;
    int maxLength = LongestSubarraySumK(arr,k);
    cout<<"The Longest Subarray's length whose Sum is K is : "<<maxLength<<endl;
    return 0;
}