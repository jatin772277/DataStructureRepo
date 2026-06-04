#include<iostream>
#include<vector>
using namespace std;
bool SearchRotatedArray(vector<int>& arr,int target){
    int n = arr.size();
    int low = 0,high = n - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == target) return true;
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low++;
            high--;
            continue;
        }
        if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target <= arr[mid]) high = mid - 1;
            else low = mid + 1;
        }
        else{
            if(arr[mid] <= target && target <= arr[high]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return false;
}
int main(){
    vector<int> arr = {3,1,2,3,3,3,3};
    int target = 2;
    bool answer = SearchRotatedArray(arr,target);
    if(answer) cout<<"Element is in array!!!!!!!!!!"<<endl;
    else cout<<"Element is not in array!!!!!!!!!!!"<<endl;
    return 0;
}