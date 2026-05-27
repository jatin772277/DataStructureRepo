#include<iostream>
#include<vector>
#include<map>
using namespace std;
//optimal if array have only poositive numbers
int LongestSubarraySumK(vector<int> &arr,int k){
    int left = 0,right = 0;
    int sum = arr[0];
    int maxLen = 0;
    while(right < arr.size()){
        while(left <= right && sum > k){
            sum -= arr[left];
            left++;
        }
        if(sum == k) maxLen = max(maxLen , right -left + 1);
        right++;
        if(right < arr.size()) sum += arr[right];
    }
    return maxLen;
}
int main(){
    vector<int> arr = {1,2,3,1,1,1,1,4,2,3};
    int k = 10;
    int maxLength = LongestSubarraySumK(arr,k);
    cout<<"The Longest Subarray's length whose Sum is K is : "<<maxLength<<endl;
    return 0;
}