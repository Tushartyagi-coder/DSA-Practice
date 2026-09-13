#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;

    node(int value){
        data = value;
        left = right = nullptr;
    }

};
node* lowestcommonancestor(node* root , int n1 , int n2){
    if( root == nullptr){
        return nullptr;
    }
    if( root -> data == n1 || root -> data == n2){
        return root;
    }
    node* leftlca = lowestcommonancestor(root -> left , n1 , n2);
    node* rightlca = lowestcommonancestor(root -> right , n1 , n2);
    if( leftlca && rightlca){
        return root;
    }
    return leftlca ? leftlca : rightlca;
}
// Problem  : Lowest Common Ancestor in Binary Tree
// Pattern  : Tree Traversal + Recursion
// TC       : O(N) where N is the number of nodes in the tree
// SC       : O(H) where H is the height of the tree (due to recursion
// approach name = divide and conquer approach
int main(){
    node* root  = new node(1);
    root->left  = new node(2);
    root->right = new node(3);
    root->left->left  = new node(4); 
    root->left->right = new node(5);
    root->right->left  = new node(6);
    root->right->right = new node(7);

    int n1 = 4, n2 = 3;
    node* lca = lowestcommonancestor(root, n1, n2);

    if (lca != nullptr) {
        cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is: " << lca->data << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }

    return 0;
}