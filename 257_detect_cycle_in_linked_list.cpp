#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
Node* makeList(vector<int>& arr){
    if(!arr.size()) return NULL;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    int n = arr.size();
    for(int i = 1;i < n;i++){
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}
bool CheckCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}
int main(){
    vector<int> arr1 = {3,1,4,6,2};
    vector<int> arr2 = {1,2,3,4,5,6,7,8,9};
    Node* head1 = makeList(arr1);
    Node* head2 = makeList(arr2);
    Node* curr = head2;
    while(curr->next) curr = curr->next;
    curr->next = head2->next->next;
    bool ans1 = CheckCycle(head1);
    bool ans2 = CheckCycle(head2);
    if(ans1) cout<<"Cycle Detected in Linked List1!!!"<<endl;
    else cout<<"No Cycle Is There in Linked List1!!!"<<endl;
    if(ans2) cout<<"Cycle Detected in Linked List2!!!"<<endl;
    else cout<<"No Cycle Is There in Linked List2!!!"<<endl;
    return 0;
}