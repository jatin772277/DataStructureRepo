#include<iostream>
#include<vector>
using namespace std;
int find_missing(vector<int> &arr,int number){
    vector<int> HashArray(number + 1, 0);
    for(int i = 0;i < arr.size();i++) HashArray[arr[i]] = 1;
    for(int i = 1;i < HashArray.size();i++) if(HashArray[i] == 0) return i;
}
int main(){
    vector<int> arr = {1,2,4,5,8,3,7};
    int number = 8;
    int missing = find_missing(arr,number);
    cout<<"The Missing number is: "<<missing<<endl;
    return 0;
}