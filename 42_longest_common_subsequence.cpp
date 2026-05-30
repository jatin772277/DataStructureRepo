#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
void printArray(vector<int> &arr){
    for(int x : arr) cout<<x<<" ";
    cout<<endl;
}
int longestConsecutiveSequence(vector<int> &arr){
    int n = arr.size();
    if(n == 0) return 0;
    int longest  =1;
    unordered_set<int> sett;
    for(int i = 0;i < arr.size();i++){
        sett.insert(arr[i]);
    }
    for(auto it : sett){
        if(sett.find(it - 1) == sett.end()){
            int count = 1;
            int x = it;
            while(sett.find(x + 1) != sett.end()){
                x = x + 1;
                count++;
            }
            longest= max(longest,count);
        }
    }
    return longest;
}
int main(){
    vector<int> arr = {100,102,100,101,101,4,3,2,3,2,1,1,1,2};
    int length = longestConsecutiveSequence(arr);
    cout<<"The Longest Consecutive Sequence's Length is: "<<length<<endl;
    return 0;
}