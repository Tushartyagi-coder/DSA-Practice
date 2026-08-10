#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    // constructor
    node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
node* createtree( node* root){
    int value;
    cout << "Enter the data for the node: ";
    cin >> value;
    if( value == -1){  // base case
        return nullptr;
    }
    root = new node(value);
    cout << "Enter left child of " << value << ":\n";
    root -> left = createtree(root -> left); // recursive call to left subtree
    cout << "Enter right child of " << value << ":\n";
    root -> right = createtree( root -> right);  // recursive call to right subtree
    return root;
}
void levelofordertraversal(node* root){
    queue<node*>q;
    q.push(root);
    while( !q.empty()){
        int size = q.size();          // we declare size so that loop will run for the number of nodes in that level
        for(int i = 0; i < size; i++){
        node *temp = q.front();
        cout << temp -> data << " ";
        q.pop();
        if( temp -> left != nullptr){
            q.push(temp -> left);
        }
        if(temp -> right != nullptr){
            q.push(temp -> right);
        }
    
    }
    cout << endl;  // it maintain the level order traversal in new line
}
}
int main(){
    node *root = nullptr;
    root = createtree(root);
      levelofordertraversal(root);
    return 0;

}
// 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1