#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left ; 
    node* right;
    // constructor
    node( int value){
        data = value;
        left = right = nullptr;
    }
};
vector<vector<int>> verticalordertraversals(node* root){   
    map<int , map<int , vector <int>>> nodes;  // data ko store or end me ans ko dene ke liye map ka use kiya hai
    queue<pair<node* , pair < int , int >>>q; //  // pure tree ko traverse ye karne ke liye queue ka use kiya hai
    vector<vector<int>>  ans;    // final answer ko store karne ke liye vector ka use kiya hai
    if( root == nullptr){
        return ans;

    }
    q.push({root, {0, 0}});
    while(!q.empty()){
        pair<node* , pair<int , int >> temp = q.front();
        q.pop();
        node* frontnode = temp .first;
        int hd = temp.second.first;
        int level = temp.second . second;
        nodes[hd][level].push_back(frontnode -> data);
        if( frontnode -> left){
            q.push({frontnode -> left , {hd - 1 , level + 1}});
        }
        if( frontnode -> right){
            q.push({frontnode -> right , {hd + 1 , level + 1}});
        }
    }
    /*
 * Problem  : Vertical Order Traversal of Binary Tree
 * Platform : GFG + LeetCode 987
 * Approach : BFS + map<col, map<level, vector<int>>>
 * Pattern  : Tree Traversal + Coordinate Mapping
 * TC       : O(N log N)
 * SC       : O(N)
 */

    for(auto i : nodes){
        vector<int> temp;
        for(auto j : i.second){
            sort(j.second.begin() , j.second.end());
            for(auto k : j.second){
                temp.push_back(k);
            }
        }
        ans.push_back(temp);
    }

    return ans;
}
// sorting also done for same level and same vertical line nodes
int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    vector<vector<int>> result = verticalordertraversals(root);

    for (const auto& col : result) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}