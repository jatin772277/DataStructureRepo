#include<iostream>
#include<vector>
#include<stack>
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
    Node* tail = head;
    int n = arr.size();
    for(int i = 1;i<n;i++){
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head;
}
bool isPalindromicLinkedList1(Node* head){
    stack<int> st;
    Node* curr = head;
    while(curr){
        st.push(curr->data);
        curr = curr->next;
    }
    curr = head;
    while(curr && !st.empty()){
        if(curr->data != st.top()) return false;
        st.pop();
        curr = curr->next;
    }
    return true;
}
Node* ReverseList(Node* head){
    if(!head || !head->next) return head;
    Node* curr = head;
    Node* prev = NULL;
    while(curr){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}
bool isPalindromicLinkedList2(Node* head){
    Node *slow = head,*fast = head,*prev = NULL;
    while(fast && fast->next){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    Node* curr = head;
    slow = ReverseList(slow);
    while(curr && slow){
        if(curr->data != slow->data) return false;
        curr = curr->next;
        slow = slow->next;
    }
    return true;
}
int main(){
    vector<int> arr1 = {1,2,3,2,1};
    vector<int> arr2 = {1,2,3,3,2,1};
    vector<int> arr3 = {1,2,3,3,2,2};
    Node* head1 = makeList(arr1);
    Node* head2 = makeList(arr2);
    Node* head3 = makeList(arr3);
    bool ans1 = isPalindromicLinkedList1(head1);
    bool ans2 = isPalindromicLinkedList1(head2);
    bool ans3 = isPalindromicLinkedList1(head3);
    if(ans1) cout<<"Linked list is Palindrome!!"<<endl;
    else cout<<"Not A Palindrome!!"<<endl;
    if(ans2) cout<<"Linked list is Palindrome!!"<<endl;
    else cout<<"Not A Palindrome!!"<<endl;
    if(ans3) cout<<"Linked list is Palindrome!!"<<endl;
    else cout<<"Not A Palindrome!!"<<endl;
    ans1 = isPalindromicLinkedList2(head1);
    ans2 = isPalindromicLinkedList2(head2);
    ans3 = isPalindromicLinkedList2(head3);
    if(ans1) cout<<"Linked list is Palindrome!!"<<endl;
    else cout<<"Not A Palindrome!!"<<endl;
    if(ans2) cout<<"Linked list is Palindrome!!"<<endl;
    else cout<<"Not A Palindrome!!"<<endl;
    if(ans3) cout<<"Linked list is Palindrome!!"<<endl;
    else cout<<"Not A Palindrome!!"<<endl;
    return 0;
}