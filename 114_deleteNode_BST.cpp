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
    root->left = buildTree(arr,2 * i + 1);
    root->right = buildTree(arr,2 * i + 2);\
    return root;
}
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int inorderSuccessor(Node* node){
    Node* temp = node->right;
    while(temp->left) temp = temp->left;
    return temp->data;
}
int inorderPredecessor(Node* node){
    Node* temp = node->left;
    while(temp->right) temp = temp->right;
    return temp->data;
}
Node* DeleteNode(Node* root,int key){  
    if(!root) return NULL;
    if(key < root->data) root->left = DeleteNode(root->left,key);
    else if(key > root->data) root->right = DeleteNode(root->right,key);
    else{
        if(root->left == NULL && root->right == NULL){
            delete root;return NULL;
        }
        if(root->left == NULL){
            Node* temp = root->right;
            delete root;return temp;
        }
        if(root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        int succ = inorderSuccessor(root);
        root->data = succ;
        root->right = DeleteNode(root->right,succ);
    }
    return root;
}
int main(){
    vector<int> arr = {8,5,12,2,7,10,13,1,3,6,8,-1,-1,-1,-1,-1,-1,-1,4};
    Node* root = buildTree(arr,0);
    cout<<"Before Deletion: ";
    inorder(root);
    cout<<endl;
    int key = 5;
    root = DeleteNode(root,key);
    cout<<"After Deletion: ";
    inorder(root);
    cout<<endl;
    return 0;
}