#include<bits/stdc++.h>
using namespace std;
int main(){
    array<int , 5> arr = {1,36,6,7,89};
    // for(size_t i = 0;i < 5;i++) cout<<arr[i]<<" ";
    // cout<<endl;
    // arr.fill(0);
    // for(size_t i = 0;i < 5;i++) cout<<arr[i]<<" ";
    // cout<<endl;
    // for(auto it = arr.begin();it != arr.end();it++) cout << (*it) <<" ";
    // cout<<endl;
    // for(auto it = arr.rbegin();it != arr.rend();it++) cout << (*it) <<" ";
    // cout<<endl;
    // for(auto it = arr.end() - 1;it >= arr.begin();it--) cout << (*it) <<" ";
    // cout<<endl;
// maximum size of an Array in main() code can be 10^6
    //For each Loop
    for(auto it : arr) cout<<it<<" ";
    cout<<endl;
    string str = "bscfwegjbhewf";
    for(auto c : str) cout<<c<<" ";
    cout<<endl;
    cout<<arr.front()<<" "<<arr.back()<<" "<<arr.size()<<endl;
    cout<<"Max Size: "<<arr.max_size()<<endl;
    array<int , 5> arr1;
    arr1.fill(6);
    arr.swap(arr1);
    cout<<"arr: "<<endl;
    for(auto it : arr) cout<<it<<" ";
    cout<<endl;
    cout<<"arr1: "<<endl;
    for(auto it : arr1) cout<<it<<" ";
    cout<<endl;
    return 0;
}