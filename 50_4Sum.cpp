#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printMatrice(vector<vector<int>> &arr){
    for(size_t i =0;i < arr.size();i++){
        cout<<"[ ";
        for(size_t j = 0;j < arr[i].size();j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<" ]";
        cout<<endl;
    }
    cout<<endl;
}
vector<vector<int>> Sum4(vector<int> &arr,int target){
    vector<vector<int>> answer;
    sort(arr.begin(),arr.end());
    for(size_t i = 0;i < arr.size();i++){
        if(i > 0 && arr[i] == arr[i-1]) continue;
        for(size_t j = i + 1;j < arr.size();j++){
            if(j > i + 1 && arr[j] == arr[j-1]) continue;
            size_t left = j + 1;
            size_t right = arr.size() - 1;
            while(left < right){
                int sum = arr[i] + arr[j] + arr[left] + arr[right];
                if(sum < target) left++;
                else if(sum > target) right--;
                else{
                    answer.push_back({arr[i],arr[j],arr[left],arr[right]});
                    left++;
                    right--;
                    while(left < right && arr[left] == arr[left - 1]) left++;
                    while(left < right && arr[right] == arr[right + 1]) right--; 
                }
            }
        }
    }
    return answer;
}
int main(){
    vector<int> arr = {-3,-2,-1,0,0,0,1,2,3};
    int target = 0;
    vector<vector<int>> answer = Sum4(arr,target);
    cout<<"QuadRuples Are like this in the array As Solution: "<<endl;
    printMatrice(answer);
    return 0;
}