#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    // constructor 
    node(int value){
        data = value;
        left = right = nullptr;
    }
};
pair<bool , int> sumoftreefast(node* root){
    if( root == nullptr){
        return {true , 0};

    }
    if( root -> left == nullptr && root -> right == nullptr){
        return {true , root -> data};
    }

    pair<bool , int> leftans = sumoftreefast(root -> left);
    pair<bool , int> rightans = sumoftreefast(root -> right);
    bool left = leftans.first;
    bool right = rightans.first;
    bool sum = root -> data == leftans.second + rightans.second;
    if( left && right && sum){
        return {true , root -> data + leftans.second + rightans.second};
    }
    else{
        return {false , 0};
    }
}
// isSumTree:
// Approach: Pair-based DFS
 // TC: O(n) — har node ek baar visit
 // SC: O(h) — h = height of tree, recursion stack
int main(){
    node* root  = new node(26);
    root->left  = new node(10);
    root->right = new node(3);
    root->left->left  = new node(4); 
    root->left->right = new node(6);
    root->right->left  = new node(3); 

    pair<bool , int> result = sumoftreefast(root);

    cout << "Is Sum Tree : " << (result.first ? "Yes" : "No") << endl; // Yes
    cout << "Sum of Tree : " << root -> data << endl; // 26

    return 0;
}
