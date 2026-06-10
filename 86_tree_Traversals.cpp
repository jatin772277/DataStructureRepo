#include<iostream>
#include<vector>
#include<queue>
#include<stack>
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
Node* MakeCompleteBinaryTree(vector<int> &arr,int i){
    if(i >= arr.size()) return NULL;
    Node* root = new Node(arr[i]);
    root->left = MakeCompleteBinaryTree(arr, 2*i + 1);
    root->right = MakeCompleteBinaryTree(arr, 2*i + 2);
    return root;
}

void preorder(Node* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void levelorder(Node* root){
    vector<vector<int>> temp;
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i =0;i < size;i++){
            Node* node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            level.push_back(node->data);
        }
        temp.push_back(level);
    }
    for(int i = 0;i < temp.size();i++){
        for(int j = 0;j < temp[i].size();j++) cout<<temp[i][j]<<" ";
    }
    cout<<endl;
}
void iterativePreorder(Node* root){
    vector<int> preorder;
    if(root == NULL) return;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        root = st.top();
        st.pop();
        preorder.push_back(root->data);
        if(root->right) st.push(root->right);
        if(root->left) st.push(root->left);
    }
    for(int x : preorder) cout<<x<<" ";
    cout<<endl;
}
void iterativeInorder(Node* root){
    stack<Node*> st;
    vector<int> inorder;
    Node* node = root;
    while(true){
        if(node){
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty() == true) break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;
        }
    }
    for(int x : inorder) cout<<x<<" ";
    cout<<endl;
}
void iterativePostOrder_2Stack(Node* root){
    vector<int> postorder;
    if(root == NULL) return;
    stack<Node*> st1,st2;
    st1.push(root);
    while(!st1.empty()){
        root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left) st1.push(root->left);
        if(root->right) st1.push(root->right);
    }
    while(!st2.empty()){
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
    for(int x : postorder) cout<<x<<" ";
    cout<<endl;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    Node* root = MakeCompleteBinaryTree(arr,0);
    cout<<"Preorder traversal: ";
    preorder(root);
    cout<<endl;
    cout<<"Inorder traversal: ";
    inorder(root);
    cout<<endl;
    cout<<"Postorder traversal: ";
    postorder(root);
    cout<<endl;
    cout<<"Levelorder(BFS) traversal: ";
    levelorder(root);
    cout<<endl;
    cout<<"Iterative Preorder traversal: ";
    iterativePreorder(root);
    cout<<"Iterative Inorder traversal: ";
    iterativeInorder(root);
    cout<<"Iterative Postorder(2Stack) traversal: ";
    iterativePostOrder_2Stack(root);
    return 0;
}