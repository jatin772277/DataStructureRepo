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
Node* LowestCommonAncestor(Node* root,Node* p,Node* q){
    if(!root || root->data == p->data || root->data == q->data) return root;
    Node* left = LowestCommonAncestor(root->left,p,q);
    Node* right = LowestCommonAncestor(root->right,p,q);
    if(!left) return right;
    else if(!right) return left;
    else return root; //As both not null so we found the result
}
int main(){
    vector<int> arr = {1,2,3,4,5,8,9,-1,-1,6,7};
    Node* root = buildTree(arr);
    Node *p = new Node(4);Node* q = new Node(9);
    Node* answer = LowestCommonAncestor(root,p,q);
    if(answer){
        cout<<"Node p "<<p->data<<" and q "<<q->data<<" Have LCA as: ";
        cout<<answer->data<<endl;
    }
    else cout<<"One of the nodes are not in tree or maybe both"<<endl;
    return 0;
}