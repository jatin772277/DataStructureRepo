#include<iostream>
#include<vector>
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
    root->left = buildTree(arr,2 * i + 1);
    root->right = buildTree(arr,2 * i + 2);\
    return root;
}
int KthSmallestBST(Node* root,int k){
    Node* curr = root;
    int currK = 0;
    while(curr){
        if(!curr->left){
            currK++;
            if(currK == k) return curr->data;
            curr = curr->right;
        }
        else{
            Node* prev = curr->left;
            while(prev->right && prev->right != curr) prev = prev->right;
            if(prev->right == NULL){
                prev->right = curr;
                curr= curr->left;
            }
            else{
                prev->right = NULL;
                currK++;
                if(currK == k) return curr->data;
                curr = curr->right;
            }
        }
    }
    cout<<"Tree Doesn't Have elements more than or equal to k!!"<<endl;
    return -1;
}
int KthLargestBST(Node* root,int k){
    Node* curr = root;
    int currK = 0;
    while(curr){
        if(curr->right == NULL){
            currK++;
            if(currK == k) return curr->data;
            curr = curr->left;
        }
        else{
            Node* next = curr->right;
            while(next->left && next->left != curr) next = next->left;
            if(next->left == NULL){
                next->left = curr;
                curr = curr->right;
            }
            else{
                next->left = NULL;
                currK++;
                if(currK == k) return curr->data;
                curr = curr->left;
            }
        }
    }
    cout<<"Tree Doesn't Have elements more than or equal to k!!"<<endl;
    return -1;
}
int main(){
    vector<int> arr = {8,5,12,2,7,10,13,1,3,6,8,-1,-1,-1,-1,-1,-1,-1,4};
    Node* root = buildTree(arr,0);
    int k = 3;
    int kSmall = KthSmallestBST(root,k);
    int kLarge = KthLargestBST(root,k);
    cout<<"Kth Smallest Element: "<<kSmall<<endl;
    cout<<"Kth Largest Element: "<<kLarge<<endl;
    return 0;
}