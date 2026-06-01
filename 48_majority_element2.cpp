#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
void printArray(vector<int> &arr){
    for(int x : arr){
        cout<<x<<" ";
    }
    cout<<endl;
}
vector<int> MajorityElements(vector<int> &arr){
    int val = arr.size() / 3;
    unordered_map<int,int> mpp;
    for(int x : arr){
        mpp[x]++;
    }
    vector<int> answer;
    for(auto it : mpp){
        if(it.second > val) answer.push_back(it.first);
    }
    sort(answer.begin(),answer.end());
    return answer;
}
int main(){
    vector<int> arr = {1,1,3,1,2,2,3,2};
    vector<int> answer = MajorityElements(arr);
    cout<<"For The array: ";
    printArray(arr);
    cout<<"There is Majority element who occurs more than floor value of arr.size()/3: ";
    printArray(answer);
    return 0;
}