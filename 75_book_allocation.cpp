#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
bool possible(vector<int> &arr,int students,int maxPage){
    int student = 1;
    long long pages = 0;
    for(int i = 0;i < arr.size();i++){
        if(arr[i] + pages <= maxPage) pages += arr[i];
        else{
            student++;
            pages = arr[i];
            if(student > students) return false;
        }
    }
    return true;
}
int MaxMinBookAllocationPages(vector<int> &arr, int students){
    int n = arr.size();
    if(students > n) return -1;
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(possible(arr,students,mid)){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
int main(){
    vector<int> arr = {25,46,28,49,24};
    int m = 4;
    int answer = MaxMinBookAllocationPages(arr,m);
    cout<<"The Maximum pages that is minimized pages while book allocation: "<<answer<<endl;
    return 0;
}