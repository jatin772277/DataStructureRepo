#include<iostream>
#include<vector>
using namespace std;
void printArray(vector<int> &arr){
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
}
vector<int> Union(vector<int> &arr, vector<int> &brr){

    int n1 = arr.size();
    int n2 = brr.size();

    int i = 0, j = 0;

    vector<int> UnionArray;

    while(i < n1 && j < n2){
        if(arr[i] <= brr[j]){
            if(UnionArray.size() == 0 || UnionArray.back() != arr[i]){
                UnionArray.push_back(arr[i]);
            }
            i++;
        }
        else{
            if(UnionArray.size() == 0 || UnionArray.back() != brr[j]){
                UnionArray.push_back(brr[j]);
            }
            j++;
        }
    }
    while(i < n1){
        if(UnionArray.size() == 0 || UnionArray.back() != arr[i]){
            UnionArray.push_back(arr[i]);
        }
        i++;
    }
    while(j < n2){
        if(UnionArray.size() == 0 || UnionArray.back() != brr[j]){
            UnionArray.push_back(brr[j]);
        }
        j++;
    }
    return UnionArray;
}
int main(){
    vector<int> arr = {1,1,2,3,4,5};
    vector<int> brr = {2,3,4,4,5,6};
    vector<int> unionOfArray = Union(arr,brr);
    printArray(arr);
    printArray(brr);
    cout<<"Union of These 2 Array: ";
    printArray(unionOfArray);
    return 0;
}