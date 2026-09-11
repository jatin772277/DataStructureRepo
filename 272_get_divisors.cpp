#include<iostream>
#include<vector>
using namespace std;
vector<int> GetDivisors(int n){
    vector<int> result;
    result.push_back(1);
    for(int i = 2;i <= (n/2);i++) if(n % i == 0) result.push_back(i);
    result.push_back(n);
    return result;
}
void PrintArray(vector<int> &arr){
    cout<<"Printing Array: ";
    for(int x : arr) cout<<x<<" ";
    cout<<endl;
}
int main(){
    int n1 = 60,n2 = 36,n3 = 49,n4 = 108;
    vector<int> arr1 = GetDivisors(n1);
    vector<int> arr2 = GetDivisors(n2);
    vector<int> arr3 = GetDivisors(n3);
    vector<int> arr4 = GetDivisors(n4);
    PrintArray(arr1);
    PrintArray(arr2);
    PrintArray(arr3);
    PrintArray(arr4);
    return 0;
}