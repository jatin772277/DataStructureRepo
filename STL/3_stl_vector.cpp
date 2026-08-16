#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printArray(vector<int> &arr){
    for(int a : arr) cout<<a<<" ";
    cout<<endl;
}
int main(){
    vector<int> arr;
    cout<<"Intial Size: "<<arr.size()<<endl;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    cout<<"Dynamic Vector: ";
    printArray(arr);
    arr.pop_back();
    cout<<"After Pop_back(): ";
    printArray(arr);
    cout<<"Updated Size: "<<arr.size()<<endl;
    //new functions
    arr.clear();
    cout<<"After clear(): ";
    cout<<"Size: "<<arr.size()<<endl;
    vector<int> vec(5,0);//->{0,0,0,0,0}
    vector<int> vec1(10,1);
    vector<int> vec2(vec1.begin(),vec1.end()); //- [)
    //vector<int> vec2(vec1);//can copy the vector too
    vector<int> vec3(vec);
    cout<<"Vector2 copied from Vector1: ";
    printArray(vec2);
    cout<<"vector3 copied from Vector0: ";
    printArray(vec3);
    vector<int> vec4(vec2.begin(),vec2.begin() + 2);
    cout<<"Vector4 : ";
    printArray(vec4);
}