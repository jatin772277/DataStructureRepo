#include<iostream>
#include<vector>
using namespace std;
void printArray(vector<int> &arr){
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
}
void Sorting012(vector<int> &arr){
    int count0 = 0,count1= 1,count2 = 0;
    for(int i = 0;i < arr.size();i++){
        if(arr[i] == 0) count0++;
        else if(arr[i] == 1) count1++;
        else count2++;
    }
    for(int i = 0;i < count0;i++) arr[i] = 0;
    for(int i = count0 ;i < count1 + count0;i++) arr[i] = 1;
    for(int i = count0 + count1 ;i < count0+ count1+count2;i++) arr[i] = 2;
}

int main(){
    vector<int> arr = {0,1,1,0,1,2,1,2,0,0,0,1,1,2,0,1,2,2,2};
    cout<<"Before Sorting: ";
    printArray(arr);
    Sorting012(arr);
    printArray(arr);
    return 0;
}