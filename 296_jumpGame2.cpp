#include<iostream>
#include<vector>
using namespace std;
int JumpGame2(vector<int>& nums) {
    int jumps = 0;
    int currentEnd = 0;
    int farthest = 0;
    for(int i = 0;i < nums.size() - 1;i++){
        farthest = max(farthest, i + nums[i]);
        if(i == currentEnd){
            jumps++;
            currentEnd = farthest;
        }
    }
    return jumps;
}
int main(){
    vector<int> nums1 = {1,2,4,1,1,0,2,5};
    int ans = JumpGame2(nums1);
    cout<<"Minimum Moves to Reach end: "<<ans<<endl;
    return 0;
}