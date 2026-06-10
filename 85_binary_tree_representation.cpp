#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* MakeCompleteBinaryTree(vector<int> &arr,int i){
    if(i >= arr.size()) return NULL;
    Node* root = new Node(arr[i]);
    root->left = MakeCompleteBinaryTree(arr, 2*i + 1);
    root->right = MakeCompleteBinaryTree(arr, 2*i + 2);
    return root;
}
void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main(){
    vector<int> arr = {4,2,6,1,3,5,7};
    Node* root = MakeCompleteBinaryTree(arr,0);
    inorder(root);
    return 0;
}