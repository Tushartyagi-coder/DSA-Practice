#include<iostream>
#include<climits>
#include<vector>
using namespace std;
pair<int, int> minmaxarray(vector<int>& arr, int n){
    // so function is returning a pair of integers (minimum and maximum)
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for( int i = 0;i<n;i++){
        if(arr[i] > maxi){
            maxi = arr[i];
        }
        if(arr[i] < mini){
            mini = arr[i];
        }
    }
    return {mini , maxi};
}
int main(){
    vector<int> arr = {4 , 6 , 2 , 8 , 1};
    pair<int, int> ans = minmaxarray(arr , 5);
    cout << "Minimum element is: " << ans.first << endl;
    cout << "Maximum element is: " << ans.second << endl;
    return 0;
}