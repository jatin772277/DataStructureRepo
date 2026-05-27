#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// void Reverse(vector<int> &arr,int start,int end){
//     while(start <= end){
//         int temp = arr[start];
//         arr[start] = arr[end];
//         arr[end] = temp;
//         start++;
//         end--;
//     }
// }
void printArray(vector<int> &arr){
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
}
void leftRotateD(vector<int> &arr,int d){
    d = d % arr.size();
    if(d == arr.size()) return;
    reverse(arr.begin(),arr.begin() + d);
    reverse(arr.begin()+d,arr.end());
    reverse(arr.begin(),arr.end());
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11};
    int d = 27;
    printArray(arr);
    leftRotateD(arr,d);
    printArray(arr);
    return 0;
}