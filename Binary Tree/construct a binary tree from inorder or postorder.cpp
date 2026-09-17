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
node* solve(vector<int> &inorder , vector<int> &postorder , int inorderstart , int inorderend , int &postindex , unordered_map<int , int> &nodetoindex , int n){
    // base case
    if( postindex < 0 || inorderstart > inorderend){
        return nullptr;
    }
    int element = postorder[postindex--];
    node* root = new node(element);
    int position = nodetoindex[element];
    // recursive calls
    root -> right = solve(inorder , postorder , position + 1 , inorderend , postindex , nodetoindex , n);
    root -> left = solve(inorder , postorder , inorderstart , position - 1 , postindex , nodetoindex , n);
    return root;
}
node* buildtreeinorderpostorder(vector<int> inorder , vector<int> postorder){
    int n = inorder.size();
    int postindex = n-1;
    unordered_map<int , int>nodetoindex;
    createmapping(inorder , nodetoindex , n);
    node* ans = solve(inorder , postorder , 0 , n-1 , postindex , nodetoindex , n);
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
int main(){
    vector<int> inorder = {4, 8, 2, 5, 1,  6 , 3, 7};
    vector<int> postorder = {8, 4, 5, 2, 6, 7, 3, 1};
    node* root = buildtreeinorderpostorder(inorder , postorder);
    cout << "Level Order Traversal of the constructed tree: ";
    cout << endl;
    printLevelOrder(root);

    return 0;
}