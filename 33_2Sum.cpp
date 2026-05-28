#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printArray(vector<int> &arr){
    for(int i = 0;i < arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
}
vector<int> Sumof2_Index(vector<int>& arr,int target){
    vector<int> answer;
    sort(arr.begin(),arr.end());
    int left = 0 ,right = arr.size()-1;
    while(left < right){
        int sum = arr[left] + arr[right];
        if(sum == target){
            answer = {left,right};
            return answer;
        }
        else if(sum < target) left++;
        else right--;
    }
    return answer;
}
int main(){
    vector<int> arr = {2,3,4,6,8,11,24};
    int target1 = 19;
    int target2 = 20;
    vector<int> answer1 = Sumof2_Index(arr,target1);
    vector<int> answer2 = Sumof2_Index(arr,target2);
    if(answer1.size() == 2){
        cout<<"The indexes on which "<<target1<<" can be retrieved by summing them are: ";
        printArray(answer1);
    }
    else cout<<"There is no any index like this!!!!"<<endl;
    if(answer2.size() == 2){
        cout<<"The indexes on which "<<target2<<" can be retrieved by summing them are: ";
        printArray(answer2);
        cout<<endl;
    }
    else cout<<"There is no any index like this!!!"<<endl;
    return 0;
}