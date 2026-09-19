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

node* createmapping(node* root , int target , unordered_map<node* ,node*>& nodetoparent){
    node* result = nullptr;
    queue<node*>q;
    q.push(root);

    nodetoparent[root] = nullptr; // root has no parent
    while(!q.empty()){
        node* front = q.front();
        q.pop();
        if(front -> data == target){
            result = front;
        }
        if(front -> left ){
            nodetoparent[front -> left] = front;
            q.push(front -> left);


        }
        if(front -> right){
            nodetoparent[front -> right] = front;
            q.push(front -> right);
        }
    }
    return result;


}

int burningtree(node* targetnode , unordered_map<node* , node*> & nodetoparent){
    unordered_map<node* , bool> visited;
    queue<node* >q;
    q.push(targetnode);
    visited[targetnode] = true;
   
    int ans = 0;
    while(!q.empty()){
        int size = q.size();
        bool spread = false;
        for( int i = 0 ; i< size ; i++){
            node* front = q.front();
            q.pop();
            if( front -> left && !visited[front -> left]){
               
                visited[front -> left] = true;
                q.push(front -> left);
                 spread = true;
                
            }
            if( front -> right && !visited[front -> right]){
                visited[front -> right] = true;
                q.push(front -> right);
                 spread = true;
            }
            node* parent = nodetoparent[front];
            if( parent && !visited[parent]){
                visited[parent] = true;
                q.push(parent);
                spread = true;
            }

        }
        if(spread){
            ans++;
        }
       

    }
    return ans; // time taken to burn the entire tree

}// pattern name = BFS + mapping of node to parent
// logic = 1. create a mapping of node to parent using BFS
// 2. start burning from the target node and keep track of time taken to burn the entire tree using BFS.    
// tc O(n) and sc O(n) where n is the number of nodes in the tree.


int amountoftime(node* root , int target ){
    unordered_map<node* , node*>nodetoparent;
    node* targetnode = createmapping(root , target , nodetoparent);
    int ans = burningtree(targetnode , nodetoparent);
    return ans;
}

int main(){
    
    node* root  = new node(1);
    root->left  = new node(2);
    root->right = new node(3);
    root->left->left  = new node(4); 
    root->left->right = new node(5);
    root->right->right = new node(6);
    root->right->right->right  = new node(9);
    root->left->right->left = new node(7);
    root->left->right->right = new node(8);
    root->right->right->right->right  = new node(10);

    int target = 8;
    int timeToBurn = amountoftime(root, target);
    cout << "Time to burn the tree starting from target " << target << ": " << timeToBurn << endl;

    return 0;


}