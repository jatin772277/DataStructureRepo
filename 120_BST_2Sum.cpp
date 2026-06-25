#include<iostream>
#include<vector>
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
Node* buildTree(vector<int> &arr,int i){
    if(i >= arr.size() || arr[i] == -1) return NULL;
    Node* root = new Node(arr[i]);
    root->left = buildTree(arr,2*i + 1);
    root->right = buildTree(arr,2*i + 2);
    return root;
}
class BSTIterator{
    stack<Node*> st;
    bool reverse = true;
    public:
    BSTIterator(Node* root,bool isReversed){
        reverse = isReversed;
        pushAll(root);
    }
    bool hasNext(){
        return !st.empty();
    }
    int next(){
        Node* node = st.top();st.pop();
        if(reverse) pushAll(node->left);
        else pushAll(node->right);
        return node->data;
    }
    private:
    void pushAll(Node* root){
        for(;root;){
            st.push(root);
            if(reverse) root = root->right;
            else root = root->left;
        }
    }
};
bool BST2Sum(Node* root,int k){
    if(!root) return false;
    BSTIterator left(root,false);
    BSTIterator right(root,true);
    int i = left.next();
    int j = right.next();
    while(i < j){
        if(i + j == k) return true;
        else if(i + j < k) i = left.next();
        else j = right.next();
    }
    return false;
}
int main(){
    vector<int> arr = {7,3,10,2,6,9,11,1,-1,5,-1,8,-1,-1,-1,-1,-1,4};
    Node* root = buildTree(arr,0);
    int k1 = 16;
    int k2 = 22;
    bool ans1 = BST2Sum(root,k1);
    bool ans2 = BST2Sum(root,k2);
    if(ans1) cout<<"There is / are pair/pairs in Tree Which Sums to: "<<k1<<endl;
    else cout<<"No Pairs for: "<<k1<<endl;
    if(ans2) cout<<"There is / are pairs in Tree Which Sums to: "<<k2<<endl;
    else cout<<"No Pairs for: "<<k2<<endl;
    return 0;
}