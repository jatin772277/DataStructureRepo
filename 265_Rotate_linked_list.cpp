#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* rotateRight(Node* head, int k) {
    if (head == nullptr || head->next == nullptr || k == 0) {
        return head;
    }

    // Find length and tail
    int length = 1;
    Node* tail = head;

    while (tail->next != nullptr) {
        tail = tail->next;
        length++;
    }

    // Avoid unnecessary rotations
    k = k % length;

    if (k == 0) {
        return head;
    }

    // Make the list circular
    tail->next = head;

    // Find the new tail
    int steps = length - k;
    Node* newTail = head;

    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // New head is after new tail
    Node* newHead = newTail->next;

    // Break the circle
    newTail->next = nullptr;

    return newHead;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;

    cout << "Original list: ";
    printList(head);

    head = rotateRight(head, k);

    cout << "After rotating right by " << k << ": ";
    printList(head);

    return 0;
}