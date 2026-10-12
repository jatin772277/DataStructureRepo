#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int CountKDiffSubarrayhelper(vector<int>& nums,int k){
    if(k < 1) return 0;
    int left = 0;
    int count = 0;
    int n = nums.size();
    unordered_map<int,int> mpp;
    for(int right = 0;right < n;right++){
        mpp[nums[right]]++;
        while(mpp.size() > k){
            mpp[nums[left]]--;
            if(mpp[nums[left]] == 0) mpp.erase(nums[left]);
            left++;
        }
        if(mpp.size() <= k) count += right - left + 1;
    }
    return count;
}
int CountKDiffSubarray(vector<int>& nums,int k){
    return CountKDiffSubarrayhelper(nums,k) - CountKDiffSubarrayhelper(nums,k-1);
}
int main(){
    vector<int> nums = {1,2,1,3,4};
    int k = 3;
    int res = CountKDiffSubarray(nums,k);
    cout<<"Number of Subarray Which have exactly K Different CHar: "<<res<<endl;
    return 0;
}