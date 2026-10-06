#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int MaxFruitsIn2Basket(vector<int> &arr){
    unordered_map<int,int> mpp;
    int left = 0;
    int maxlen = 0;
    int n = arr.size();
    for(int right = 0;right < n;right++){
        mpp[arr[right]]++;
        if(mpp.size() > 2){
            mpp[arr[left]]--;
            if(mpp[arr[left]] == 0) mpp.erase(arr[left]);
            left++;
        }
        if(mpp.size() <= 2) maxlen = max(maxlen,right - left + 1);
    }
    return maxlen;
}
int main(){
    vector<int> arr = {3,3,3,1,2,1,1,3,3,4};
    int result = MaxFruitsIn2Basket(arr);
    cout<<"Result: "<<result<<endl;
    return 0;
}