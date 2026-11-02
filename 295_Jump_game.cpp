#include<iostream>
#include<vector>
using namespace std;
bool JumpGame(vector<int>& nums){
    int maxind = 0;
    int n = nums.size();
    for(int i = 0;i < n;i++){
        if(i > maxind) return false;
        maxind = max(maxind,i + nums[i]);
        if(maxind >= (n-1)) return true;
    }
    return true;
}
int main(){
    vector<int> nums1 = {1,2,4,1,1,0,2,5};
    vector<int> nums2 = {1,2,3,1,1,0,2,5};
    bool ans1 = JumpGame(nums1);
    bool ans2 = JumpGame(nums2);
    if(ans1) cout<<"We can Reach The End!!!!!!"<<endl;
    else cout<<"We Can't Reach The End!!!!!!!"<<endl;
    if(ans2) cout<<"We can Reach The End!!!!!!"<<endl;
    else cout<<"We Can't Reach The End!!!!!!!"<<endl;
    return 0;
}