#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int Moore_voting_algorithm(vector<int> &arr){
    int element;
    int count = 0;
    for(int i = 0;i < arr.size();i++){
        if(count == 0){
            element = arr[i];
            count = 1;
        }
        else if(element = arr[i]) count++;
        else count--;
    }
    count = 0;
    for(int i = 0;i < arr.size();i++){
        if(arr[i] == element) count++;
    }
    if(count > (arr.size() / 2)) return element;
    else return -1;
}
int main(){
    vector<int> arr1 = {2,2,1,3,3,1,2,2,2};
    vector<int> arr2 = {2,2,3,1,3,2,2,3,3};
    int answer1 = Moore_voting_algorithm(arr1);
    int answer2 = Moore_voting_algorithm(arr2);
    if(answer1 == -1) cout<<"Majority element does not exists!!"<<endl;
    else cout<<"Majority element is: "<<answer1<<endl;
    if(answer2 == -1) cout<<"Majority element does not exists!!"<<endl;
    else cout<<"Majority element is: "<<answer2<<endl;
    return 0;
}