#include<bits/stdc++.h>
using namespace std;
struct node{
int data;
node* left ;
node* right;
// constructor
node(int value){
    data  = value;
    left = right = nullptr;
}
};
void createmapping(vector<int> & inorder , unordered_map<int , int> &nodetoindex , int n){
    for(int i = 0 ; i < n ; i++){
        nodetoindex[inorder[i]] = i;
    }
}
node* solve(vector<int> &inorder , vector<int> &preorder , int inorderstart , int inorderend , int &preorderindex , unordered_map<int , int> &nodetoindex , int n){
    // base case
    if( preorderindex >= n || inorderstart > inorderend){
        return nullptr;
    }
    int element = preorder[preorderindex++];
    node* root = new node(element);
    int position = nodetoindex[element];
    // recursive calls
      root -> left = solve(inorder , preorder , inorderstart , position - 1 , preorderindex , nodetoindex , n);
    root -> right = solve(inorder , preorder , position + 1 , inorderend , preorderindex , nodetoindex , n);
  
    return root;
}
node* buildtreeinorderpreorder(vector<int> inorder , vector<int> preorder){
    int n = inorder.size();
    int preorderindex = 0;
    unordered_map<int , int>nodetoindex;
    createmapping(inorder , nodetoindex , n);
    node* ans = solve(inorder , preorder , 0 , n-1 , preorderindex , nodetoindex , n);
    return ans;
}
void printLevelOrder(node* root){
    if(root == nullptr) return;
    
    queue<node*> q;
    q.push(root);
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        if(temp == nullptr){
            cout << "N ";
            continue;  // null ke children mat daalo
        }
        
        cout << temp->data << " ";
        q.push(temp->left);
        q.push(temp->right);
    }
    cout << endl;
}
// pattern name = DFS + level order traversal
// approach name = construct a binary tree from inorder and preorder
// sc = O(n) + O(h) = O(n)  // for vector and recursive stack space
// tc = O(n)  // for traversing all the nodes
int main(){
    vector<int> inorder = {3, 1, 4, 0, 5, 2};
    vector<int> preorder = {0, 1, 3, 4, 2, 5};
    node* root = buildtreeinorderpreorder(inorder , preorder);
    cout << "Level Order Traversal of the constructed tree: ";
    cout << endl;
    printLevelOrder(root);

    return 0;
}