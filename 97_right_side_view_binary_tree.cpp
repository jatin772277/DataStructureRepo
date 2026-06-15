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
    int i = 1;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();q.pop();
        if(i < arr.size() && arr[i] != -1){
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;
        if(i < arr.size() && arr[i] != -1){
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }i++;
    }
    return root;
}
vector<int> RightSideView(Node* root){
    vector<int> arr;
    if(!root) return arr;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i = 0;i < size;i++){
            Node* curr = q.front();q.pop();
            if(i == size - 1) arr.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    return arr;
}
vector<int> LeftSideView(Node* root){
    vector<int> arr;
    if(!root) return arr;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i = 0;i < size;i++){
            Node* curr = q.front();q.pop();
            if(i == 0) arr.push_back(curr->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    return arr;
}
int main(){
    vector<int> arr = {1,2,3,4,5,-1,7,-1,-1,6,-1,-1,-1,-1,-1};
    Node* root = buildTree(arr);
    vector<int> answer = RightSideView(root);
    cout<<"Right Side View: ";
    for(int x : answer) cout<<x<<" ";
    cout<<endl;
    vector<int> answer1 = LeftSideView(root);
    cout<<"Left Side View: ";
    for(int x : answer1) cout<<x<<" ";
    cout<<endl;
    return 0;
}