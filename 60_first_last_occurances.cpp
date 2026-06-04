#include<iostream>
#include<vector>
using namespace std;
int LowerBound(vector<int>& arr,int x){
    int low = 0,high = arr.size() - 1;
    int ans = arr.size();
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] >= x){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
int upperBound(vector<int>& arr, int x) {
    int low = 0, high = arr.size() - 1;
    int ans = arr.size();

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}
pair<int,int> firstLastOccur(vector<int> &arr,int x){
    pair<int,int> temp = {-1,-1};
    int low = LowerBound(arr,x);
    int high = upperBound(arr,x) - 1;
    if(arr[low] == x) temp = {low,high};
    return temp;
}
int main(){
    vector<int> arr = {2,4,6,8,8,8,11,13};
    int x = 8;
    pair<int,int> pairr = firstLastOccur(arr,x);
    cout<<"First Occurance of "<<x<<" is "<<pairr.first<<" and last occurance is: "<<pairr.second<<endl;
    return 0;
}