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
pair<int,int> diametertofaster(node* root){
    if( root == nullptr){
        return {0,0}; // first value is height and second value is diameter
    }
    pair<int,int>left = diametertofaster(root -> left);
    pair<int,int> right = diametertofaster(root -> right);
    
    int option1 = left.first; // diameter of left subtree
    int option2 = right.first; // diameter of right subtree
    int option3 = left.second + right.second + 1; // diameter passing through the root node
     pair<int,int>ans;
     ans.first = max({option1, option2 , option3}); // diameter
     ans.second =max(left.second, right.second) + 1; // height
     return ans;


}
int main() {
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    node* root  = new node(1);
    root->left  = new node(2);
    root->right = new node(3);
    root->left->left  = new node(4);
    root->left->right = new node(5);

    pair<int,int> result = diametertofaster(root);

    cout << "Diameter : " << result.first  << endl; // 4
    cout << "Height   : " << result.second << endl; // 3

    return 0;
}    