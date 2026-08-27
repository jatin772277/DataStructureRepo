#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
void insertAtTail(Node*& head, int value) {
    Node* newNode = new Node(value);
    if(!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}
void removeDuplicates(Node* head) {
    if(!head) return;
    Node* curr = head;
    while(curr && curr->next) {
        if(curr->data == curr->next->data) {
            Node* duplicate = curr->next;
            curr->next = duplicate->next;
            if(duplicate->next) duplicate->next->prev = curr;
            delete duplicate;
        }
        else curr = curr->next;
    }
}
void printDLL(Node* head) {
    Node* curr = head;
    Node* prevN = NULL;
    while(curr) {
        prevN = curr;
        cout << curr->data;
        if(curr->next) cout << " <-> ";
        curr = curr->next;
    }
    cout << endl;
    cout<<"print From back: ";
    curr = prevN;
    while(curr){
        cout<<curr->data;
        if(curr->prev) cout<<" <-> ";
        curr = curr->prev;
    }
    cout<<endl;
}
int main() {
    Node* head = nullptr;
    vector<int> values = {1, 1, 1, 2, 3, 3, 4};
    for(int value : values) insertAtTail(head, value);
    cout << "Before removing duplicates: ";
    printDLL(head);
    removeDuplicates(head);
    cout << "After removing duplicates: ";
    printDLL(head);
    return 0;
}