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
 vector<vector<int>> diagonalview(node* root){
    map<int , vector <int>> nodes;  // data ko store or end me ans ko dene ke liye map ka use kiya hai
    queue<pair<node* , int >>q; //  // pure tree ko traverse ye karne ke liye queue ka use kiya hai
    vector<vector<int>>  ans;    // final answer ko store karne ke liye vector ka use kiya hai
    if( root == nullptr){
        return ans;

    }
    q.push({root, 0});
    while(!q.empty()){
        pair<node* , int > temp = q.front();
        q.pop();
        node* frontnode = temp .first;
        int d = temp.second;
        nodes[d].push_back(frontnode -> data);
        if( frontnode -> left){
            q.push({frontnode -> left , d + 1});
        }
        if( frontnode -> right){
            q.push({frontnode -> right , d});
        }
    }
    for(auto i : nodes){
        ans.push_back(i.second);
    }

    return ans;
}
// Problem  : Diagonal View of Binary Tree
// Pattern  : Tree Traversal + Coordinate Mapping
// TC       : O(N log N) map sort the tree and then traverse the tree so O(N log N)
// SC       : O(N) number of nodes in the tree

int main(){
    node* root = new node(8);
    root->left = new node(3);
    root->right = new node(10);
    root->left->left = new node(1);
    root->left->right = new node(6);
     root->left->right->left   = new node(4);
      root->left->right->right  = new node(7);
    root->right->right = new node(14);
    root->right->right->left = new node(13);

    vector<vector<int>> result = diagonalview(root);

    cout << "Diagonal View of Binary Tree:" << endl;
    for (const auto& diagonal : result) {
        for (int val : diagonal) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}