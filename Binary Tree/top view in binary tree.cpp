#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
    // constructor
    node( int value){
        data = value ;
        left = right = nullptr;
    }

};
vector<int> topview(node* root){
    vector<int>ans;
    if( root == nullptr) return ans;
    map<int , int> topnodes; // map< horizontal distance , node data>
    queue<pair<node* , int>>q; // queue< node* , horizontal distance>
    q.push({root , 0});
    while(!q.empty()){
pair<node* , int> temp = q.front();
        q.pop();
        node* frontnode = temp.first;
        int hd = temp.second;
        if( topnodes.find(hd) == topnodes.end()){
            topnodes[hd] = frontnode -> data;
        }
        if( frontnode -> left){
            q.push({frontnode -> left , hd - 1});
        }
        if( frontnode -> right){
            q.push({frontnode -> right , hd + 1});
        }

    }
    for( auto it : topnodes){
        ans.push_back(it.second);
    }
    return ans;
}
// pattern name = BFS + map<horizontal distance , node data>
// approach name = top view of binary tree
// sc = O(n) + O(n) = O(n)  // for queue and map
// tc = O(n log n)  // for map insertion
int main(){
    node* root = new node(1);
    root -> left = new node(2);
    root -> right = new node(3);
    root -> left -> left = new node(4);
    root -> left -> right = new node(5);
    root -> right -> left = new node(6);
    root -> right -> right = new node(7);
    vector<int> ans = topview(root);
    for( int i = 0 ; i< ans.size() ; i++){
        cout << ans[i] << " ";
    }
    return 0;
}