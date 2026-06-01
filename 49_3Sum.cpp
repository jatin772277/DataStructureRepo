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
vector<vector<int>> Sum3(vector<int> &arr){
    vector<vector<int>> answer;
    sort(arr.begin(),arr.end());
    for(size_t i = 0;i < arr.size();i++){
        if(i > 0 && arr[i] == arr[i-1]) continue;
        size_t left = i + 1;
        size_t right = arr.size() - 1;
        while(left < right){
            int sum = arr[i] + arr[left] + arr[right];
            if(sum < 0) left++;
            else if(sum > 0) right--;
            else{
                vector<int> temp = {arr[i],arr[left],arr[right]};
                answer.push_back(temp);
                left++;
                right--;
                while(left < right && arr[left] == arr[left - 1]) left++;
                while(left < right && arr[right] == arr[right + 1]) right--;
            }
        }
    }
    return answer;
}
int main(){
    vector<int> arr = {-1,0,1,2,-1,-4};
    vector<vector<int>> answer = Sum3(arr);
    cout<<"Triplets in The array as Solution: "<<endl;
    printMatrice(answer);
    return 0;
}