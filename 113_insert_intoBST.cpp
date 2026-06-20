#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
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
Node* InsertNode(Node* root,int newNode){
    if(!root) return new Node(newNode);
    Node* curr = root;
    while(true){
        if(curr->data <= newNode){
            if(curr->right != NULL) curr = curr->right;
            else{
                curr->right = new Node(newNode);break;
            }
        }
        else{
            if(curr->left != NULL) curr = curr->left;
            else{
                curr->left = new Node(newNode);
                break;
            }
        }
    }
    return root;
}
int main(){
    vector<int> arr = {4,2,7,1,3,5};
    int newNode = 9;
    Node* root = buildTree(arr,0);
    cout<<"Before insertion: ";
    inorder(root);
    cout<<endl;
    root = InsertNode(root,newNode);
    cout<<"After insertion: ";
    inorder(root);
    cout<<endl;
    return 0;
}