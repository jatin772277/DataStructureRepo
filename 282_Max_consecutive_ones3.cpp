#include<iostream>
#include<vector>
using namespace std;
int MaxOnesK(vector<int>& arr,int k){
    int left = 0;
    int zeros = 0;
    int maxlen = 0;
    int n = arr.size();
    for(int right = 0;right < n;right++){
        if(arr[right] == 0) zeros++;
        if(zeros > k){
            if(arr[left] == 0) zeros--;
            left++;
        }
        if(zeros <= k) maxlen = max(maxlen,right-left+1);
    }
    return maxlen;
}
int main(){
    vector<int> arr = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    int MaxOneWithKZeroAllowed = MaxOnesK(arr,k);
    cout<<"Result: "<<MaxOneWithKZeroAllowed<<endl;
    return 0;
}