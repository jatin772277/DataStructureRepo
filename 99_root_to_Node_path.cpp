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
        Node* curr = q.front();
        q.pop();
        if(i < arr.size() && arr[i] != -1){
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }i++;
        if(i < arr.size() && arr[i] != -1){
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }i++;
    } 
    return root;
}
bool getPath(Node* root,vector<int> &arr,int node){
    if(!root) return false;
    arr.push_back(root->data);
    if(root->data == node) return true;
    if(getPath(root->left,arr,node) || getPath(root->right,arr,node)) return true;
    arr.pop_back();
    return false;
}
vector<int> RootToNodePath(Node* root,int node){
    vector<int> arr;
    if(!root) return arr;
    getPath(root,arr,node);
    return arr;
}
int main(){
    vector<int> arr = {1,2,3,4,5,-1,-1,-1,-1,6,7};
    Node* root = buildTree(arr);
    int node = 7;
    vector<int> answer = RootToNodePath(root,node);
    cout<<"Path from Root to Node "<<node<<" is: ";
    for(int i = 0;i < answer.size();i++){
        if(i < (answer.size() - 1)) cout<<answer[i]<<"->";
        else cout<<answer[i]<<endl;
    }
    return 0;
}