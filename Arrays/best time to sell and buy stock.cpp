#include<bits/stdc++.h>
using namespace std;
int stock( vector<int> & prices){
    int n = prices.size();
    int max_profit = 0;
    int mini_price = INT_MAX;
    for( int i = 0 ; i< n ; i++){
        mini_price = min( mini_price , prices[i]);
        max_profit = max( max_profit , prices[i] - mini_price);
    }
    return max_profit;
}
// sc : O(1)
// tc : O(n)
// pattern name =greedy algorithm
// approach name Track min price + max profit in single pass
int main(){
    vector<int>prices = {7,1,5,3,6,4};
    int ans = stock(prices);
    cout << " maximum profit is : " << ans << endl; // 5
    return 0;
}