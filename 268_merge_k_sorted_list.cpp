#include<iostream>
#include<vector>
#include<queue>
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
void PrintList(Node* head){
    Node* curr = head;
    cout<<"List: ";
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}
Node* MakeList(vector<int> &arr){
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
Node* Merge2List(Node* head1,Node* head2){
    if(!head1 && !head2) return NULL;
    if(!head1 && head2) return head2;
    if(head1 && !head2) return head1;
    Node* l1 = head1;
    Node* l2 = head2;
    Node* result = nullptr;
    Node* tail = nullptr;
    while(l1 && l2){
        int value;
        if(l1->data <= l2->data){
            value = l1->data;
            l1 = l1->next;
        }
        else{
            value = l2->data;
            l2 = l2->next;
        }
        if(!result){
            result = new Node(value);
            tail = result;
        }
        else{
            tail->next = new Node(value);
            tail = tail->next;
        }
    }
    if(l1) tail->next = l1;
    if(l2) tail->next = l2;
    return result;
}
Node* MergeKSortedList(vector<Node*> Heads){
    Node* result = nullptr;
    int n = Heads.size();
    for(int i = 1;i < n;i++) Heads[i] = Merge2List(Heads[i-1],Heads[i]);
    return Heads[n-1];
}
Node* MergeKSortedList2(vector<Node*> heads){
    priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>> pq;
    for(int i = 0;i < heads.size();i++){
        if(heads[i]){
            pq.push({heads[i]->data,heads[i]});
        }
    }
    Node* dummy = new Node(-1);
    Node* curr = dummy;
    while(!pq.empty()){
        Node* temp = pq.top().second;
        pq.pop();
        if(temp->next) pq.push({temp->next->data,temp->next});
        curr->next = temp;
        curr = temp;
    }
    return dummy->next;
}
int main(){
    vector<int> arr1 = {2,4,6};
    vector<int> arr2 = {1,5};
    vector<int> arr3 = {1,1,3,7};
    vector<int> arr4 = {8};
    vector<vector<int>> mat = {arr1,arr2,arr3,arr4};
    vector<Node*> arr(4);
    for(int i = 0;i < 4;i++) arr[i] = MakeList(mat[i]);
    
    cout<<"Printing Before Merging: ";
    for(int i = 0;i < 4;i++){
        PrintList(arr[i]);
        cout<<endl;
    }
    Node* merged = MergeKSortedList(arr);
    cout<<"After Merging: ";
    PrintList(merged);
    
    Node* merged2 = MergeKSortedList2(arr);
    cout<<"After Merging: ";
    PrintList(merged2);
    return 0;
}