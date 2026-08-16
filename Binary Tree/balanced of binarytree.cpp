#include<bits/stdc++.h>
using namespace std;
struct node{
  int data;
  node* left;
  node* right;
  node( int value){
    data = value;
    left = right = nullptr;
  }
};
// approached name = fastbalanced
pair<bool , int> fastbalanced(node* root){
    if( root == nullptr){
        return{true , 0}; // first value is balanced or not and second value is height
    }
    pair<bool , int>left = fastbalanced(root -> left);
    pair<bool , int>right = fastbalanced(root -> right);

    bool leftans = left.first;
    bool rightans = right.first;
    bool difference = abs(left.second - right.second) <= 1;
    pair<bool , int > ans;
    ans.second = max(left.second , right.second) + 1; // height
    ans .first = leftans && rightans && difference; // balanced or not
    return ans;
}
// tc O(n) and sc O(h) where h is the height of the tree.
int main() {
    node* root  = new node(1);
    root->left  = new node(2);
    root->right = new node(3);
    root->left->left  = new node(4); 
    root->left->right = new node(5);

    pair<bool , int> result = fastbalanced(root);

    cout << "Is Balanced : " << (result.first ? "Yes" : "No") << endl; // Yes
    cout << "Height      : " << result.second << endl; // 3

    return 0;
}