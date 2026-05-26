#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int> &arr){
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void merge(vector<int> &arr,int left,int right,int mid){
    int n1 = mid - left+1;
    int n2 = right -mid;
    int L[n1],R[n2];
    for(int i = 0;i < n1;i++) L[i] = arr[left + i];
    for(int i = 0;i < n2;i++) R[i] = arr[mid + 1 + i];

    int i = 0,j = 0,k = left;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]) arr[k] = L[i++];
        else arr[k] = R[j++];
        k++;
    }
    while(i < n1){
        arr[k++] = L[i++];
    }
    while(j < n2){
        arr[k++] = R[j++];
    }
}
void Merge_Sort(vector<int>& arr,int left,int right){
    if(left >= right) return;
        int mid = left + (right - left) / 2;
        Merge_Sort(arr,left,mid);
        Merge_Sort(arr,mid+1,right);
        merge(arr,left,right,mid);
}
int main(){
    vector<int> arr = {23,34,43,12,11,17,41,25};
    printVector(arr);
    cout<<"Sorted Order: ";
    Merge_Sort(arr,0,arr.size() - 1);
    printVector(arr);
    return 0;
}