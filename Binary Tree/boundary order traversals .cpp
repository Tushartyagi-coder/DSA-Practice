#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node* left;
  node* right;
  // constructor
  node( int value){
    data = value;
    left = right = nullptr;
  }
};
vector<int> boundaryinleftpart( node* root , vector<int>& ans){
    if( (root == nullptr) ||( (root -> left == nullptr) && (root -> right == nullptr))) return {};
    ans.push_back(root -> data);
    if(root -> left) boundaryinleftpart(root -> left , ans);
    else if( root -> right) boundaryinleftpart(root -> right , ans);
    return ans;
}
void boundaryofleafpart( node* root , vector<int> &ans){
    if( (root == nullptr) ) return ;
    if(
     (root -> left == nullptr) && (root -> right == nullptr)) {
    ans.push_back(root -> data);
    return ;
    
}
boundaryofleafpart(root -> left , ans);
boundaryofleafpart(root -> right , ans);
}

vector<int> boundaryinrightpart( node* root , vector<int>&ans){
    if( (root == nullptr) || ((root -> left == nullptr) && (root -> right == nullptr))) return {};
    if(root -> right) boundaryinrightpart(root -> right , ans);
    else if( root -> left) boundaryinrightpart(root -> left , ans);
    ans.push_back(root -> data);
    return  ans;
}


vector<int> boundaryoftree( node* root){
 vector<int> ans;
if(root == nullptr) return ans;
ans.push_back(root->data);

boundaryinleftpart(root->left, ans);
boundaryofleafpart(root->left, ans);
boundaryofleafpart(root->right, ans);
boundaryinrightpart(root->right, ans);
return ans;
}
// Approach Name:
// Boundary Traversal of Binary Tree
// Pattern Name:
// DFS (Depth-First Search) — teenon parts mein recursion use kiya
// sc O(h) — h = height of tree, recursion stack
// tc O(n) — har node ek baar visit

int main(){
    //1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root -> left -> right -> left = new node(8);
    root -> left -> right -> right = new node(9);
     vector<int> ans = boundaryoftree(root);  // call karo
    
    for(auto x : ans) {
        cout << x << " ";  // print karo
    }
    cout << endl;
    return 0;
}