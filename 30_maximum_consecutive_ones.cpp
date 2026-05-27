#include<iostream>
#include<vector>
using namespace std;
int MaximumConsecutiveOnes(vector<int>& arr){
    int maxi = 0;
    int currmax = 0;
    for(int i = 0;i < arr.size();i++){
        if(arr[i] == 1){
            currmax++;
            maxi = max(maxi,currmax);
        }
        if(arr[i] == 0){
            currmax = 0;
        }
    }
    return maxi;
}
int main(){
    vector<int> arr = {1,1,1,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,1,1,1,1,1,1,1,0,0,0,1};
    int MCOnes = MaximumConsecutiveOnes(arr);
    cout<<"The Maximum Length of Subarray which Have consecutive ones is: "<<MCOnes<<endl;
    return 0;
}