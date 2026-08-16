#include<iostream>
using namespace std;
void ReverseArray(int *arr,int l,int r){
    if(l >= r) return;
    swap(arr[l],arr[r]);
    ReverseArray(arr,l+1,r-1);
}
void ReverseArray2(int *arr,int i,int size){
    if(i >= size/2) return ;
    swap(arr[i],arr[size-1-i]);
    ReverseArray2(arr,i+1,size);
}
int main(){
    int arr[] = {1,2,4,7,6,3,5,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int x : arr) cout<<x<<" ";
    cout<<endl;
    ReverseArray(arr,0,n-1);
    for(int x : arr) cout<<x<<" ";
    cout<<endl;
    ReverseArray2(arr,0,8);
    for(int x : arr) cout<<x<<" ";
    cout<<endl;
    return 0;
}