#include<bits/stdc++.h>
using namespace std;
int main(){
    // Basic
    // // priority_queue<int> pq;
    // // pq.push(1);
    // // pq.push(5);
    // // pq.push(2);
    // // pq.push(6);
    // // cout<<pq.top()<<endl;
    // // pq.pop();
    // // cout<<pq.top()<<endl;

    // //Pair
    // priority_queue<pair<int,int>> pq1;
    // pq1.push({2,7});
    // pq1.push({1,7});
    // pq1.push({1,6});
    // pq1.push({1,3});
    // pq1.push({1,5});
    // cout<<pq1.top().first<<" : "<<pq1.top().second<<endl;
    // pq1.pop();
    // cout<<pq1.top().first<<" : "<<pq1.top().second<<endl;

    //Minimum Priority queue
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(6);
    pq.push(3);
    pq.push(5);
    pq.push(1);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    return 0;
}