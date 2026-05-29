#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> NextPermutation(vector<int> &arr){
    int ind = -1;
    int n = arr.size();
    for(int i = n - 2;i >= 0;i--){
        if(arr[i] < arr[i+1]){
            ind = i;
            break;
        }
    }
    if(ind == -1){
        reverse(arr.begin(),arr.end());
        return arr;
    }
    for(int i = n - 1;i >= ind;i--){
        if(arr[i] > arr[ind]){
            swap(arr[i],arr[ind]);
            break;
        }
    }
    reverse(arr.begin() + ind + 1,arr.end());
    return arr;
}
void printArray(vector<int> &arr){
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
}
int main(){
    vector<int> arr = {5,4,3,1,2};
    cout<<"Next Permutation for ";
    printArray(arr);
    cout<<" is: ";
    vector<int> answer = NextPermutation(arr);
    printArray(answer);
    return 0;
}