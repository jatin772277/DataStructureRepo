#include<bits/stdc++.h>
using namespace std;

void printMultiset(multiset<int> &ms){
    for(auto it = ms.begin();it != ms.end();it++) cout<<(*it)<<" ";
    cout<<endl;
}
int main(){
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.emplace(2);
    ms.emplace(2);
    ms.emplace(3);
    printMultiset(ms);
    cout<<"In the multiset there is "<<ms.count(2)<<" Occurancves of 2!!"<<endl;
    ms.erase(ms.find(2));//ms.find() finds first occurance of 2 and ms.erase deletes it!!
    cout<<"After Deleting first occurance of 2!!!"<<endl;
    printMultiset(ms);
}