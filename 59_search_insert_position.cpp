#include<iostream>
#include<vector>
using namespace std;
int SearchInsert(vector<int>& arr,int m){
    int n = arr.size();
    int low = 0,high = n-1;
    int ans = 0;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] >= m){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
int main(){
    vector<int> arr = {1,2,4,7};
    int m = 6;
    int m1  = 4;
    int idx1 = SearchInsert(arr,m);
    int idx2 = SearchInsert(arr,m1);
    cout<<"The index at which we can search or insert the element: "<<idx1<<endl;
    cout<<"The index at which we can search or insert the element: "<<idx2<<endl;
    return 0;
}