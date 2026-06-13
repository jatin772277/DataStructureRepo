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
Node* buildTree(vector<int>& arr){
    if(arr.empty() || arr[0] == -1) return NULL;
    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while(!q.empty() && i < arr.size()){
        Node* curr = q.front();
        q.pop();
        // Left child
        if(i < arr.size() && arr[i] != -1){
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;
        // Right child
        if(i < arr.size() && arr[i] != -1){
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
bool isLeaf(Node* root){
    if(!root->left && !root->right) return true;
    else return false;
}
void addLeftBoundary(Node* root,vector<int> &res){
    Node* cur = root->left;
    while(cur){
        if(!isLeaf(cur)) res.push_back(cur->data);
        if(cur->left) cur = cur->left;
        else cur = cur->right;
    }
}
void addRightBoundary(Node* root,vector<int> &res){
    Node* cur = root->right;
    vector<int> temp;
    while(cur){
        if(!isLeaf(cur)) temp.push_back(cur->data);
        if(cur->right) cur = cur->right;
        else cur = cur->left;
    }
    for(int i = temp.size() - 1;i >= 0;i--) res.push_back(temp[i]);
}
void addLeaves(Node* root,vector<int>& res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }
    if(root->left) addLeaves(root->left,res);
    if(root->right) addLeaves(root->right,res);
}
vector<int> printBoundary(Node* root){
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root->data);
    addLeftBoundary(root,res);
    addLeaves(root,res);
    addRightBoundary(root,res);
    return res;
}
int main(){
    vector<int> arr = {1,2,7,3,-1,-1,8,-1,4,9,-1,5,6,10,11};
    Node* root = buildTree(arr);
    vector<int> answer = printBoundary(root);
    cout<<"Traversal: ";
    for(int x : answer) cout<<x<<" ";
    cout<<endl;
    return 0;
}
