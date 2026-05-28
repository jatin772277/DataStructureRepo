#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int Majority_element(vector<int> &arr){
    int n = arr.size();
    unordered_map<int,int> mpp;
    for(int i =0;i < arr.size();i++){
        mpp[arr[i]]++;
    }
    for(auto it = mpp.begin();it != mpp.end();it++){
        if(it->second > (n/2)) return it->first;
    }
    return -1;
}
int main(){
    vector<int> arr1 = {2,2,1,3,3,1,2,2,2};
    vector<int> arr2 = {2,2,3,1,3,2,2,3,3};
    int answer1 = Majority_element(arr1);
    int answer2 = Majority_element(arr2);
    if(answer1 == -1) cout<<"Majority element does not exists!!"<<endl;
    else cout<<"Majority element is: "<<answer1<<endl;
    if(answer2 == -1) cout<<"Majority element does not exists!!"<<endl;
    else cout<<"Majority element is: "<<answer2<<endl;
    return 0;
}