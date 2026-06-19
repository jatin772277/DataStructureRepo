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
vector<int> getInorderMorris(Node* root){
    vector<int> inorder;
    Node* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else{
            Node* prev = curr->left;
            while(prev->right && prev->right != curr) prev = prev->right;
            if(prev->right == NULL){
                prev->right = curr;
                curr = curr->left;
            }
            else{
                prev->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return inorder;
}
vector<int> getPreorderMorris(Node* root){
    vector<int> inorder;
    Node* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else{
            Node* prev = curr->left;
            while(prev->right && prev->right != curr) prev = prev->right;
            if(prev->right == NULL){
                prev->right = curr;
                inorder.push_back(curr->data);
                curr = curr->left;
            }
            else{
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return inorder;
}
int main(){
    vector<int> arr = {1,2,3,4,5,-1,-1,-1,-1,-1,6};
    Node* root = buildTree(arr,0);
    cout<<"Inorder Traversal: ";
    vector<int> ans = getInorderMorris(root);
    for(int x : ans) cout<<x<<" ";
    cout<<endl;
    cout<<"Preorder Traversal: ";
    vector<int> ans1 = getPreorderMorris(root);
    for(int x : ans1) cout<<x<<" ";
    cout<<endl;
    return 0;
}