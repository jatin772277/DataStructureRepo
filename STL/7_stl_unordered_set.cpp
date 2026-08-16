#include<bits/stdc++.h>
using namespace std;
void printUnordered_set(unordered_set<int> &st){
    for(auto it = st.begin();it!=st.end();it++) cout<<(*it)<<" ";
    cout<<endl<<endl;
}
int main(){
    unordered_set<int> st;
    for(int i = 0;i < 5;i++) st.insert(2*i + 7);
    printUnordered_set(st);
    st.erase(7);
    printUnordered_set(st);
    //There is no any rbegin and rend iterator for unordered set
    cout<<st.size()<<" is the size of set!!"<<endl;
}