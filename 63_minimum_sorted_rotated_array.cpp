#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int findMinSortedRotated(vector<int>& arr){
    int n = arr.size();
    int low = 0,high = n - 1;
    int ans = INT_MAX;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[low] <= arr[mid]){
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else{
            high = mid - 1;
            ans = min(ans,arr[mid]);
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {4,5,6,7,0,1,2};
    int min = findMinSortedRotated(arr);
    cout<<"Minimum: "<<min<<endl;
    return 0;
}