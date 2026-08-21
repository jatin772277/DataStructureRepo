#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
    Node(int val,Node* next1){
        data = val;
        next = next1;
    }
};
Node* MakeList(vector<int>& arr){
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
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
Node* SortList(Node* head){
    int count0 = 0,count1= 0;
    Node* temp = head;
    while(temp){
        if(temp->data == 0) count0++;
        else if(temp->data == 1) count1++;
        temp = temp->next;
    }
    temp = head;
    while(temp){
        if(count0){
            temp->data = 0;
            count0--;
        }
        else if(count1){
            temp->data = 1;
            count1--;
        }
        else temp->data = 2;
        temp = temp->next;
    }
    return head;
}
Node* SortList2(Node* head){
    if(!head || !head->next) return head;
    Node* curr = head;
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    Node *zero = zeroHead,*one = oneHead,*two = twoHead;
    while(curr){
        if(curr->data == 0){
            zero->next = curr;
            zero = curr;
        }
        else if(curr->data == 1){
            one->next = curr;
            one = curr;
        }
        else if(curr->data == 2){
            two->next = curr;
            two = curr;
        }
        curr = curr->next; 
    }
    zero->next = oneHead->next;
    one->next = twoHead->next;
    return zeroHead->next;
}
int main(){
    vector<int> arr = {1,1,2,1,1,0,1,0,1,2,2,0,0,1,2};
    Node* head = MakeList(arr);
    cout<<"Before Sorting: ";
    printList(head);
    head = SortList(head);
    cout<<"After Sorting: ";
    printList(head);
    vector<int> arr2 = {1,1,2,1,1,0,1,0,1,2,2,0,0,1,2};
    Node* head1 = MakeList(arr2);
    cout<<"Before Sorting: ";
    printList(head1);
    head1 = SortList2(head1);
    cout<<"After Sorting: ";
    printList(head1);
    return 0;
}