#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left  = NULL;
        right  = NULL;
    }
};
Node* buildTree(vector<int> &arr,int i){
    if(i >= arr.size() || arr[i] == -1) return NULL;
    Node* root = new Node(arr[i]);
    root->left = buildTree(arr,2*i + 1);
    root->right = buildTree(arr,2*i + 2);
    return root;
}
class Solution{
    Node* first;
    Node* prev;
    Node* middle;
    Node* last;
    public:
    void inorderTraverse(Node* root){
        if(!root) return;
        inorderTraverse(root->left);
        cout<<root->data<<" ";
        inorderTraverse(root->right);
    }
    void inorder(Node* root){
        if(!root) return;
        inorder(root->left);
        if(prev != NULL && root->data < prev->data){
            if(!first){
                first = prev;
                middle = root;
            }
            else last = root;
        }
        prev = root;
        inorder(root->right);
    }
    void RecoverBST(Node* root){
        first = middle = last = NULL;
        prev = new Node(INT_MIN);
        inorder(root);
        if(first && last) swap(first->data,last->data);
        else if(first && middle) swap(first->data,middle->data);
    }
};
int main(){
    vector<int> arr1 = {3,1,4,-1,-1,2};
    vector<int> arr2 = {4,2,3,1,6,5,7};
    Solution object1;
    Solution object2;
    Node* root1 = buildTree(arr1,0);
    Node* root2 = buildTree(arr2,0);
    cout<<"First Tree Without Recovered: ";
    object1.inorderTraverse(root1);
    cout<<endl;
    cout<<"Second Tree Without Recovered: ";
    object2.inorderTraverse(root2);
    cout<<endl;
    object1.RecoverBST(root1);
    object2.RecoverBST(root2);
    cout<<"First Tree After Being Recovered: ";
    object1.inorderTraverse(root1);
    cout<<endl;
    cout<<"Second Tree After Being Recovered: ";
    object2.inorderTraverse(root2);
    cout<<endl;
    return 0;
}