#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    // constructor
    node( int value){
        data = value ;
        left = right = nullptr;
    }
};
vector<int> zigzagorder( node* root){
    vector<int>answer;
    if( root == nullptr) return {};
    queue<node*>q;
    q.push(root);
    bool lefttoright = true;
    while(!q.empty()){
      
        int size = q.size();
          vector<int>ans(size);

        for( int i = 0 ; i< size ; i++ ){
            node* temp = q.front();
            q.pop();

         int index = lefttoright ? i : size - i - 1;
         ans[index] = temp->data;
         if( temp->left) q.push(temp->left);
         if( temp->right) q.push(temp->right);
        }

        for(auto i : ans){
            answer.push_back(i);
        }
        lefttoright = !lefttoright;
    }
    return answer;
}
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    vector<int> result = zigzagorder(root);
    for(int i : result){
        cout<<i<<" ";
    }
    return 0;
}
 

                