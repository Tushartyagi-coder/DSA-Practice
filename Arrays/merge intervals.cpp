// merge intervals 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
   vector<vector<int>> merge(vector<vector<int>>& intervals) { // class function so no direct call then use solution class otherwise not use
        sort(intervals.begin() , intervals.end());
        vector<vector<int>>result;
        int n = intervals.size();
        result.push_back(intervals[0]);
        for( int i = 1 ; i < n ; i++){
            if( result.back()[1]  < intervals[i][0]){

        result.push_back(intervals[i]);

            }
            else{
                result.back()[1] = max( result.back()[1] , intervals[i][1]);
            }   
             }
        return result;
    }
    // time complexity O(n log n) , space complexity  =  O(n);
    // intervals merging with greedy approach;
    int main(){
         vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
        vector<vector<int>> ans = merge(intervals);

    cout << "Merged Intervals:\n";

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

    }