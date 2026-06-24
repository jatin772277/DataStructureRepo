#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* buildTree(vector<int> &arr, int i) {
    if (i >= arr.size() || arr[i] == -1)
        return NULL;

    Node* root = new Node(arr[i]);

    root->left = buildTree(arr, 2 * i + 1);
    root->right = buildTree(arr, 2 * i + 2);

    return root;
}

class BSTIterator {
public:
    stack<Node*> st;

    void pushAll(Node* root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
    }

    BSTIterator(Node* root) {
        pushAll(root);
    }

    int next() {
        Node* node = st.top();
        st.pop();

        pushAll(node->right);

        return node->data;
    }

    bool hasNext() {
        return !st.empty();
    }
};

int main() {

    vector<int> arr = {7, 3, 15, -1, -1, 9, 20};
    Node* root = buildTree(arr, 0);
    BSTIterator it(root);
    cout<<it.next()<<endl;      // 3
    cout<<it.next()<<endl;      // 7
    cout<<it.hasNext()<<endl;   // 1
    cout<<it.next()<<endl;      // 9
    cout<<it.hasNext()<<endl;   // 1
    cout<<it.next()<<endl;      // 15
    cout<<it.hasNext()<<endl;   // 1
    cout<<it.next()<<endl;      // 20
    cout<<it.hasNext()<<endl;   // 0
    return 0;
}