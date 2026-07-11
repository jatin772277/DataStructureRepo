#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data= val;
        left = NULL;
        right = NULL;
    }
};
Node* makeTree(vector<int>& arr,int i){
    if(i >= arr.size() || arr[i] == -1) return NULL;
    Node* root = new Node(arr[i]);
    root->left = makeTree(arr,2*i + 1);
    root->right = makeTree(arr,2*i + 2);
    return root;
}
vector<string> binaryTreePaths(Node* root) {
    vector<string> result;
    if(!root) return result;
    stack<pair<Node*,string>> st;
    st.push({root,to_string(root->data)});
    while(!st.empty()){
        Node* node = st.top().first;
        string path = st.top().second;
        st.pop();
        if(!node->left && !node->right) result.push_back(path);
        if(node->right){
            st.push({node->right,path + "->" + to_string(node->right->data)});
        }
        if(node->left){
            st.push({node->left,path + "->" + to_string(node->left->data)});
        }
    }
    return result;
}
int main(){
    vector<int> arr = {1,2,3,-1,5,6,7,-1,-1,-1,-1,-1,-1,-1,8};
    Node* root = makeTree(arr,0);
    vector<string> ans = binaryTreePaths(root);
    cout<<"root to leaf All paths: "<<endl;
    for(string str : ans){
        cout<<str<<endl;
    }
    cout<<endl;
    return 0;
}