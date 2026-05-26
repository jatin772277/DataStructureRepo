#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void printArray(vector<int> &arr){
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
}
vector<int> removeDuplicates(vector<int> &arr){
    unordered_map<int,int> freqMap;
    vector<int> ans;
    for(int i =0;i < arr.size();i++){
        if(freqMap[arr[i]] == 0){
            ans.push_back(arr[i]);
            freqMap[arr[i]]++;
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {11,12,11,13,14,16,17,18,16};
    printArray(arr);
    arr = removeDuplicates(arr);
    printArray(arr);
    return 0;
}