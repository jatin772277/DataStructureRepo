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
void printList(Node* head){
    Node* curr = head;
    while(curr){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}
Node* IntersectionOfTwoList1(Node* head1,Node* head2){
    if(!head1 || !head2) return NULL;
    unordered_map<Node*,int> mpp;
    Node* curr = head1;
    while(curr){
        mpp[curr] = 1;
        curr = curr->next;
    }
    curr = head2;
    while(curr){
        if(mpp.find(curr) != mpp.end()) return curr;
        curr = curr->next;
    }
    return NULL;
}
Node* giveNode(Node* head1,Node* head2){
    Node *curr1 = head1,*curr2 = head2;
    while(curr1 && curr2){
        if(curr1 == curr2) return curr1;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return NULL;
}
Node* IntersectionOfTwoList2(Node* head1,Node* head2){
    if(!head1 || !head2) return NULL; 
    Node* curr1 = head1;
    Node* curr2 = head2;
    int len1 = 0,len2 = 0;
    while(curr1 && curr2){
        len1++;len2++;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    while(curr1){
        len1++;
        curr1 = curr1->next;
    }
    while(curr2){
        len2++;
        curr2 = curr2->next;
    }
    curr1 = head1;
    curr2 = head2;
    int diff = len2 - len1;
    if(diff > 0){
        for(int i = 0;i < diff;i++) curr2 = curr2->next;
        return giveNode(curr1,curr2);
    }
    else if(diff < 0){
        for(int i = 0;i < abs(diff);i++) curr1 = curr1->next;
        return giveNode(curr1,curr2);
    }
    else return giveNode(curr1,curr2);
}
Node* IntersectionOfTwoList3(Node* head1,Node* head2){
    if(!head1 || !head2) return NULL;
    Node* curr1 = head1;
    Node* curr2 = head2;
    while(curr1 != curr2){
        if(curr1) curr1 = curr1->next;
        else curr1 = head2;
        if(curr2) curr2 = curr2->next;
        else curr2 = head1;
    }
    return curr1;
}
int main(){
    vector<int> arr = {3,1,4,6,2};
    vector<int> support = {1,2,4,5};
    Node* head1 = makeList(arr);
    Node* head2 = makeList(support);
    Node* curr = head2;
    while(curr->next) curr = curr->next;
    curr->next = head1->next->next;
    Node* result = IntersectionOfTwoList1(head1,head2);
    cout<<"Intersecting Node: "<<result->data<<endl;
    Node* result1 = IntersectionOfTwoList2(head1,head2);
    cout<<"Intersecting Node: "<<result1->data<<endl;
    Node* result2 = IntersectionOfTwoList3(head1,head2);
    cout<<"Intersecting Node: "<<result2->data<<endl;
    return 0;
}