#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int SubarraysWithXorK(vector<int> &arr,int k){
    unordered_map<int,int> mpp;
    int xorr = 0;
    int count = 0;
    mpp[0] = 1;//for the subarrays who starts with index 0;
    for(int i = 0;i < arr.size();i++){
        xorr ^= arr[i];
        int required = xorr ^ k;
        count += mpp[required];
        mpp[xorr]++;
    }
    return count;
}
int main(){
    vector<int> arr = {4,2,2,6,4};
    int k = 6;
    int answer = SubarraysWithXorK(arr,k);
    cout<<"Number of Subarrays in the array with Xor of K: "<<answer<<endl;
    return 0;
}