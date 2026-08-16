#include<bits/stdc++.h>
using namespace std;

int main(){

    queue<int> q;

    // inserting elements
    q.push(10);
    q.push(20);
    q.emplace(30);   // faster insertion
    q.push(40);
    q.push(50);

    cout<<"Front element: "<<q.front()<<endl;
    cout<<"Rear element: "<<q.back()<<endl;

    cout<<"Size of queue: "<<q.size()<<endl;

    // popping element
    cout<<"Element "<<q.front()<<" removed"<<endl;
    q.pop();

    cout<<"New front element: "<<q.front()<<endl;
    cout<<"Size after pop: "<<q.size()<<endl;

    // checking empty
    if(q.empty())
        cout<<"Queue is empty"<<endl;
    else
        cout<<"Queue is not empty"<<endl;

    // creating another queue
    queue<int> q2;
    q2.push(100);
    q2.push(200);

    cout<<"\nBefore swap:"<<endl;
    cout<<"q front: "<<q.front()<<endl;
    cout<<"q2 front: "<<q2.front()<<endl;

    // swapping queues
    q.swap(q2);

    cout<<"\nAfter swap:"<<endl;
    cout<<"q front: "<<q.front()<<endl;
    cout<<"q2 front: "<<q2.front()<<endl;

    // deleting whole queue
    cout<<"\nDeleting all elements from q:"<<endl;
    while(!q.empty()){
        cout<<q.front()<<" popped"<<endl;
        q.pop();
    }

    cout<<"Final size of q: "<<q.size()<<endl;

    return 0;
}