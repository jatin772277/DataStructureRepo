#include<iostream>
#include<vector>
using namespace std;
int merge(vector<int> &arr,int low,int mid,int high){
    int count = 0;
    int right = mid + 1;
    for(int i = low;i <= mid;i++){
        while(right <= high && arr[i] > 2LL * arr[right]) right++;
        count += (right - (mid + 1));
    }
    vector<int> temp;
    int left = low;
    right = mid + 1;

    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]) temp.push_back(arr[left++]);
        else temp.push_back(arr[right++]);
    }
    while(left <= mid) temp.push_back(arr[left++]);
    while(right <= high) temp.push_back(arr[right++]);
    for(int i = low;i <= high;i++){
        arr[i] = temp[i - low];
    }
    return count;
}
int mergeSort(vector<int> &arr,int low ,int high){
    if(low >= high) return 0;
    int mid = low + (high - low) / 2;
    int count = 0;
    count += mergeSort(arr,low,mid);
    count += mergeSort(arr,mid + 1,high);
    count += merge(arr,low,mid,high);
    return count;
}
int ReversePairs(vector<int> &arr){
    return mergeSort(arr,0,arr.size() - 1);
}
int main(){
    vector<int> arr = {40,25,19,12,9,6,2};
    int answer = ReversePairs(arr);
    cout<<"Reverse Pairs : i < j and arr[i] > 2 * arr[j]"<<endl;
    cout<<"Number of Reverse Pairs in the array: "<<answer<<endl;
    return 0;
}