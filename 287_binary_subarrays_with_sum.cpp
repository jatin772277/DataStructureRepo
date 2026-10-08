#include <iostream>
#include <vector>
using namespace std;

int function(vector<int>& nums,int k){
    if(k < 0) return 0;

    int left = 0,count = 0;
    long long sum = 0;

    for(int right = 0;right < nums.size();right++){
        sum += nums[right];

        while(sum > k){
            sum -= nums[left];
            left++;
        }

        count += right-left+1;
    }

    return count;
}
int numSubarraysWithSum(vector<int>& nums,int goal){
    return function(nums,goal)-function(nums,goal-1);
}
int main(){
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;
    cout << numSubarraysWithSum(nums,goal) << endl;
    return 0;
}