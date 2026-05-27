#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int AppearingOnce(vector<int> &arr){
    unordered_map<int,int> sett;
    for(int i = 0;i < arr.size();i++){
        sett[arr[i]]++;
    }
    for(auto it : sett){
        if(it.second == 1) return (it.first);
    }
    return -1;
}
int main(){
    vector<int> arr = {1,1,4,5,6,7,5,4,6};
    int ans = AppearingOnce(arr);
    cout<<"Element that is appearing once in array : "<<ans;
    cout<<endl;
    return 0;
}