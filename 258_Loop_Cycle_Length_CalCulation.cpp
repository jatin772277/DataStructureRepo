#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
class Solution {
public:
    int lengthOfLoop(Node* head) {
        if(!head || !head->next) return 0;
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                int cnt = 1;
                Node* temp = slow->next;
                while(temp != slow) {
                    temp = temp->next;
                    cnt++;
                }
                return cnt;
            }
        }
        return 0;
    }
};

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next->next;
    Solution obj;
    cout << "Length of loop: " << obj.lengthOfLoop(head) << endl;
    return 0;
}