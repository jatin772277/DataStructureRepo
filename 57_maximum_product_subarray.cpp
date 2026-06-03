#include<iostream>
#include<vector>
using namespace std;
int MaximumProductSubarray(vector<int> &arr){
    int minProd = arr[0];
    int maxProd = arr[0];
    int ans = arr[0];
    for(int i = 1;i < arr.size();i++){
        if(arr[i] < 0) swap(maxProd ,minProd);
        maxProd = max(arr[i] , maxProd * arr[i]);
        minProd = min(arr[i] , minProd * arr[i]);
        ans = max(ans , maxProd);
    }
    return ans;
}
int main(){
    vector<int> arr = {-2,3,0,-2,4,-1};
    int answer = MaximumProductSubarray(arr);
    cout<<"Maximum Product of Subarray is: "<<answer<<endl;
    return 0;
}