#include<bits/stdc++.h>
using namespace std;
struct node{
 int data;
 struct node*left;
    struct node*right;
    // constructor
    node(int value)
    {
        data = value;
        left = right = nullptr;
    }
};
void postorder(node* node){
    if( node == nullptr){
        return;
    }
    postorder( node -> left);
    postorder( node -> right);
    cout << node -> data << " "; // we print the data of the node after traversing both left and right subtrees
}
int main(){
    struct node* root = new node(1);  // heap me memory allocate hoti hai
    root -> left = new node(2);
    root -> right = new node(3);
    root -> left -> left = new node(4);
    root -> left -> right = new node(5);
    root -> left -> right -> left = new node(6);
    root -> right -> left = new node(7);
    root -> right -> right = new node(8);
    root -> right -> right -> left = new node(9);
    root -> right -> right -> right = new node(10);
    postorder(root);
    return 0;

}