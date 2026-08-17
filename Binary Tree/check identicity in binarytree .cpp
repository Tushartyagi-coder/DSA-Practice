#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    // constructor
    node( int value){
        data = value;
        left = right = nullptr;
    }
};
bool istreesame(node* a, node* b){
  if( a == nullptr  || b == nullptr){
    return a == b;
  }
    bool left = istreesame(a -> left , b -> left);
    bool right = istreesame(a -> right , b -> right);
    
    bool val = a -> data == b-> data;
    if( left && right && val){
        return true;
    }
    else{
        return false;
    }
}
// TC = O(N) — visit every node once
 // SC = O(H) — recursion stack, worst case O(N) for skewed tree
int main(){
    // Tree 1:
    //       1
    //      / \
    //     2   3
    node* root1 = new node(1);
    root1->left  = new node(2);
    root1->right = new node(3);

    // Tree 2: (same)
    node* root2 = new node(1);
    root2->left  = new node(2);
    root2->right = new node(3);

    // Tree 3: (different)
    node* root3 = new node(1);
    root3->left  = new node(2);
    root3->right = new node(99); // alag value

    cout << istreesame(root1, root2) << endl; // 1 (true)
    cout << istreesame(root1, root3) << endl; // 0 (false)

    return 0;
}