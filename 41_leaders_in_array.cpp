#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
void printArray(vector<int> &arr){
    for(int x : arr) cout<<x<<" ";
    cout<<endl;
}
vector<int> Leaders(vector<int> &arr){
    vector<int> answer;
    int maximum = INT_MIN;
    int n = static_cast<int>(arr.size());
    for(int i = n - 1; i >= 0; --i){
        if(arr[i] > maximum){
            answer.push_back(arr[i]);
            maximum = arr[i];
        }
    }
    reverse(answer.begin(),answer.end());
    return answer;
}
int main(){
    vector<int> arr = {10,22,12,3,0,6};
    vector<int> answer = Leaders(arr);
    cout<<"For the Array: ";
    printArray(arr);
    cout<<"Leaders Elements Are: ";
    printArray(answer);
    return 0;
}