#include<iostream>
#include<vector>
#include<queue>
#include<sstream>
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
void inorderTraversal(Node* root){
    if(!root) return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
Node* buildTree(vector<int> &arr,int i){
    if(i >= arr.size() || arr[i] == -1) return NULL;
    Node* root = new Node(arr[i]);
    root->left = buildTree(arr,2*i + 1);
    root->right = buildTree(arr,2*i + 2);
    return root;
}
string serialize(Node* root){
    if(!root) return "";
    string str = "";
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();q.pop();
        if(curr == NULL) str.append("#,");
        else str.append(to_string(curr->data) + ',');
        if(curr != NULL){
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    cout<<"String Generated: "<<str<<endl;
    return str;
}
Node* deserialize(string data){
    if(data.size() == 0) return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    Node* root = new Node(stoi(str));
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();q.pop();
        getline(s,str,',');
        if(str == "#") curr->left = NULL;
        else{
            Node* leftNode = new Node(stoi(str));
            curr->left = leftNode;
            q.push(leftNode);
        }
        getline(s,str,',');
        if(str == "#") curr->right = NULL;
        else{
            Node* rightNode = new Node(stoi(str));
            curr->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
int main(){
    vector<int> arr = {1,2,13,-1,-1,4,5};
    Node* root = buildTree(arr,0);
    inorderTraversal(root);
    cout<<endl;
    string serializedTree = serialize(root);
    Node* root1 = deserialize(serializedTree);
    inorderTraversal(root1);
    cout<<endl;
    return 0;
}