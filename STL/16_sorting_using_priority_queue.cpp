#include<bits/stdc++.h>
using namespace std;
vector<int> sorting(vector<int> &vec){
    priority_queue<int , vector<int> , greater<int>> pq;
    for(int x : vec) pq.push(x);
    vector<int> temp;
    while(!pq.empty()){
        int a = pq.top();
        temp.push_back(a);
        pq.pop();
    }
    return temp;
}
void printVector(vector<int> &vec){
    cout<<"Vector: ";
    for(int x : vec) cout<<x<<" ";
    cout<<endl; 
}
int main(){
    vector<int> vec;
    vec.push_back(6);
    vec.push_back(6);
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(5);
    cout<<"Unsorted: "<<endl;
    printVector(vec);
    vec = sorting(vec);
    cout<<"Sorted: "<<endl;
    printVector(vec);
    return 0;
}