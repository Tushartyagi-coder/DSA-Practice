#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
    // constructor
    node( int value){
        data = value;
        left = right = nullptr;
    }
};
void leftview(node* root , int level , vector<int> &ans){
    if( root == nullptr) return;
    if( level == ans.size()){
        ans.push_back(root -> data);

    }
    leftview(root -> left , level + 1 , ans);
    leftview(root -> right , level + 1 , ans);
}
void rightview(node* root , int level ,  vector<int> &ans){
    if( root == nullptr) return;
    if( level  == ans.size()){ {
        ans.push_back(root -> data);
        
    }
    rightview(root -> right , level + 1 , ans);
    rightview(root -> left , level + 1 , ans);
}
}
// pattern name = DFS + level order traversal
// approach name = left and right view of binary tree
// sc = O(n) + O(h) = O(n)  // for vector and recursive stack space
// tc = O(n)  // for traversing all the nodes
int main(){
    
    node* root = new node(1);
    root -> left = new node(2);
    root -> right = new node(3);
    root -> left -> left = new node(4);
    root -> left -> right = new node(5);
    root -> right -> left = new node(6);
    root -> right -> right = new node(7);

    vector<int> leftAns;
    
    leftview(root, 0, leftAns);

    cout << "Left View: ";
    for (int val : leftAns) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> rightAns;
   
    rightview(root, 0, rightAns);

    cout << "Right View: ";
    for (int val : rightAns) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}