#include<iostream>
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
void flatten(node* root){
    node* current = root;
    while(current != nullptr){
        if(current -> left != nullptr){
            node* predecessor = current -> left;
            while(predecessor -> right != nullptr){
                predecessor = predecessor -> right;
            }
            predecessor -> right = current -> right;
            current -> right = current -> left;
            current -> left = nullptr;
        }
        current = current -> right;
    }
}
// tc : O(n) sc: O(1)
// This function flattens a binary tree into a linked list in-place using Morris traversal.
int main(){
    node* root = new node(1);
    root -> left = new node(2);
    root -> right = new node(3);
    root -> left -> left = new node(4);
    root -> left -> right = new node(5);
    flatten(root);
    cout << "Flattened binary tree (linked list): ";
    node* current = root;
    while(current != nullptr){
        cout << current -> data << " ";
        current = current -> right;
    }
    return 0;
}