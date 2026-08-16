#include<bits/stdc++.h>
using namespace std;

void printSet(set<int> &st){
    for(auto it = st.begin();it!=st.end();it++)cout<<(*it)<<" ";
    cout<<endl;
}
int main(){
    // int arr[] = {1,3,4,2,3,4,5,6};
    // set<int> st;
    // for(int a : arr) st.insert(a);
    // cout<<st.size()<<" is the Set of The Size!!\n";
    // cout<<"That Means Array have "<<st.size()<<" Unique Elements!!"<<endl;
    // st.erase(st.begin());
    // cout<<"After deleting Set Size: "<<st.size()<<endl;
    // auto it = st.begin();
    // advance(it, 2);
    // st.erase(st.begin(), it);
    // cout<<"After deleting 2 More Elements then Set Size: "<<st.size()<<endl;
    // for(auto it1 = st.begin(); it1 != st.end();it1++) cout<<(*it1)<<" ";
    // cout<<endl;
    // st.erase(4);
    // cout<<"Deleting 4 By st.erase(4)!!"<<endl;
    // cout<<"Now Set Look Likes: ";
    // for(auto it2 = st.begin();it2!=st.end();it2++) cout<<(*it2)<<" ";
    // cout<<endl;
    set<int> st = {1,3,5,7};
    set<int> st1(st.begin(),prev(st.end(),2));
    cout<<"Printing Set 1: ";
    printSet(st);
    cout<<"Printing Set2: ";
    printSet(st1);

    set<int> st2 = {1,2,3,4,5,7,6,8,9,10};
    auto it = st2.find(7);
    auto it1 = st2.find(11);
    if(it != st2.end()) cout<<"Iterator of 7: "<<(*it)<<endl;
    if(it1 != st2.end()) cout<<"Iterator of 11 that is not in set: "<<(*it1)<<endl;
    else cout<<"Iterator of 11 that is not in set: "<<"NOT FOUND"<<endl;
}