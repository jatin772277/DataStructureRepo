#include<iostream>
#include<vector>
using namespace std;
int NumberLongestIncreasingSubsequence(vector<int>& arr){
    int n = arr.size();
    vector<int> len(n,1);
    vector<int> count(n,1);
    int maxi = 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < i;j++){
            if(arr[j] < arr[i]){
                if(len[j] + 1 > len[i]){
                    len[i] = len[j] + 1;
                    count[i] = count[j];
                }
                else if(len[j] + 1 == len[i]){
                    count[i] += count[j];
                }
            }
        }
        maxi = max(maxi,len[i]);
    }
    int ans = 0;
    for(int i = 0;i < n;i++){
        if(len[i] == maxi){
            ans += count[i];
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {1,2,5,4,7};
    int count = NumberLongestIncreasingSubsequence(arr);
    cout<<"Count is: "<<count<<endl;
    return 0;
}