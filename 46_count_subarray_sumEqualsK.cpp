#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int countSubarrays(vector<int> &arr,int k){
    unordered_map<int,int> mp;
    mp[0] = 1;
    int prefixSum = 0;
    int count = 0;
    for(int num : arr){
        prefixSum += num;
        if(mp.find(prefixSum-k) != mp.end()) count += mp[prefixSum - k];
        mp[prefixSum]++;
    }
    return count;
}
int main(){
    vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};
    int k = 3;
    int answer = countSubarrays(arr,k);
    cout<<"Number of Subarrays whose Sum is K: "<<answer<<endl;
    return 0;
}