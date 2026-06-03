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

int main(){
    vector<int> arr = {3,5,8,15,19};
    int x = 8;
    int answer1 = LowerBound(arr,x);
    int answer2 = upperBound(arr,x);
    cout<<"Lower Bound exist on the index(smallest): "<<answer1<<endl;
    cout<<"Upper Bound exist on the index(smallest): "<<answer2<<endl;
}