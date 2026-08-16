#include<bits/stdc++.h>
using namespace std;

int main(){
    stack<int> st;
    st.push(2);
    st.push(4);
    st.push(3);
    st.push(1);
    st.push(9);
    st.push(4);
    st.push(7);
    cout<<"Top element of the Stack is: "<<st.top()<<endl;
    int a = st.top();
    st.pop();
    cout<<"Element "<<a<<" popped from the stack!!!"<<endl;
    cout<<"After Popping Top element of the Stack is: "<<st.top()<<endl;
    cout<<"The size of stack is: "<<st.size()<<endl;
    if(st.empty()) cout<<"Stack is Empty!!!"<<endl;
    else cout<<"Stack isn't Empty!!!!"<<endl;
    cout<<"Deleting the Whole Stack!!!"<<endl;
    while(!st.empty()){
        int b = st.top();
        cout<<"Element "<<b<<" got Popped!!!"<<endl;
        st.pop();
    }
    cout<<"After Deleting Whole Stack The Size is: "<<st.size()<<endl;
    return 0;
}