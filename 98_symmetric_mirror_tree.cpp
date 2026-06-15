#include<iostream>
#include<vector>
#include<queue>
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

Node* buildTree(vector<int> &arr){
    if(arr.empty() || arr[0] == -1) return NULL;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;

    while(!q.empty() && i < arr.size()){
        Node* curr = q.front();
        q.pop();

        if(i < arr.size() && arr[i] != -1){
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        if(i < arr.size() && arr[i] != -1){
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}
bool check(Node* left,Node* right){
    if(!left && !right) return true;
    if(!left || !right) return false;
    if(left->data != right->data) return false;
    return check(left->left,right->right) && check(left->right,right->left);
}
bool isSymmetric(Node* root){
    if(!root) return true;
    return check(root->left,root->right);
}
int main(){
    vector<int> arr1 = {1,2,2,3,4,4,3};
    vector<int> arr2 = {1,2,2,-1,3,-1,3};
    Node* root1 = buildTree(arr1);
    Node* root2 = buildTree(arr2);
    bool a1 = isSymmetric(root1);
    bool a2 = isSymmetric(root2);
    if(a1) cout<<"First tree is Symmetric"<<endl;
    else cout<<"First tree is Not Symmetric"<<endl;
    if(a2) cout<<"Second tree is Symmetric"<<endl;
    else cout<<"Second tree is Not Symmetric"<<endl;
    return 0;
}