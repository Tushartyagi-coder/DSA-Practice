#include<iostream>
#include<queue>
using namespace std;

struct node{
   int data;
   node* right;
   node* left;

   node(int value){
    data = value;
    left = right = nullptr;

   }
};
void levelofordertraversal(node* root){
    queue<node*>q;
    q.push(root);
    while( !q.empty()){
        int size = q.size();               // we declare size so that loop will run for the number of nodes in that level
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
void preorder(node* node){
    if( node == nullptr){
        return;
    }
    cout << node -> data << " ";
    preorder(node -> left);
    preorder(node -> right);

}
void postorder(node* node){
    if( node == nullptr){
        return;
    }
    postorder( node -> left);
    postorder( node -> right);
    cout << node -> data << " "; // we print the data of the node after traversing both left and right subtrees
}
void inorder( node * node){
    if( node == nullptr){
        return;
    }
    inorder( node -> left);
    cout << node -> data << " ";
    inorder( node -> right);
}
node* insertinbst(node* root , int data){

  if( root == nullptr){
    root = new node(data);
    return root;
  }
  if(data > root -> data){
    root -> right = insertinbst(root -> right , data);
  }

    if(data < root -> data){
    root -> left= insertinbst(root -> left , data);
  }
  return root;
  
}
void takeinput(node* &root ){
  int data;
  cin>> data;
  while( data != -1){
    root = insertinbst(root , data);
    cin >> data;
    }
}
node* minvalue(node* root){
    node* temp = root;

    while(temp->left != nullptr){
        temp = temp->left;
    }

    return temp;
}

node* deletefrombst(node* root , int value){
    if(root == nullptr){
        return nullptr;
    }
    // for 0 child;
    if(root -> data == value){
        if( root -> left == nullptr && root -> right == nullptr){
            delete root;
            return nullptr;
        }
        //for 1 child;
        // for left;
        if(root -> left != nullptr && root -> right == nullptr){
            node* temp = root -> left;
            delete root;
            return temp;
        }
        // for right;
        if( root -> left == nullptr && root -> right != nullptr){
            node* temp = root -> right;
            delete root;
            return temp;
        }
        // for 2 child;
        if( root -> left != nullptr && root -> right != nullptr){
            int mini = minvalue(root -> right) -> data ;
            root -> data = mini;
            root -> right = deletefrombst(root -> right , mini);
            return root;
        }

    }
    else if( root -> data > value){
        root -> left = deletefrombst(root -> left , value);
        return root;
    }
    else {
        root -> right = deletefrombst(root -> right , value);
            return root;
    }
}
// sc = O(h) and in worst case O(n) 
// tc = O(n);
int main(){

    node* root = nullptr;

    cout << "Enter data for BST: " << endl;
    takeinput(root);

    cout << "\nBST before deletion:" << endl;
    levelofordertraversal(root);

    cout << "\nInorder before deletion:" << endl;
    inorder(root);
    cout << endl;

    // Delete a node having 2 children
    int value;
    cout << "\nEnter value to delete: ";
    cin >> value;

    root = deletefrombst(root, value);

    cout << "\nBST after deletion:" << endl;
    levelofordertraversal(root);

    cout << "\nInorder after deletion:" << endl;
    inorder(root);
    cout << endl;

    return 0;
}