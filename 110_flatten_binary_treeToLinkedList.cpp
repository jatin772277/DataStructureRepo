#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left  =NULL;
        right = NULL;
    }
};
Node* buildTree(vector<int> &arr,int i){
    if(i >= arr.size() || arr[i] == -1) return NULL;
    Node* root = new Node(arr[i]);
    root->left = buildTree(arr,2*i + 1);
    root->right = buildTree(arr,2*i + 2);
    return root;
}
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void flattenTree(Node* root){
    Node* curr = root;
    while(curr){
        if(curr->left){
            Node* runner = curr->left;
            while(runner->right) runner = runner->right;
            runner->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}
int main(){
    vector<int> arr = {1,2,5,3,4,-1,6,-1,-1,-1,-1,-1,-1,7};
    Node* root = buildTree(arr,0);
    cout<<"Inorder Before Flatten: ";
    inorder(root);
    cout<<endl;
    flattenTree(root);
    cout<<"Inorder After Flatten: ";
    inorder(root);
    cout<<endl;
    return 0;
}