// minimise the height 2 
// question 9 done by me on 11/07/2026;
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int MinimizetheHeight(vector<int> &arr ,  int k){
    sort(arr.begin() , arr.end());
    int n = arr.size();
    int ans = arr[n-1] - arr[0];
    int smallest = arr[0] + k;
    int largest = arr[n-1] - k;
    for( int i = 0 ; i < n- 1; i++){
        int mini = min(smallest , arr[i+1] - k);
        int maxi = max(largest , arr[i] + k);
        ans = min(ans , maxi - mini);
    }
    return ans;
}
int main(){
    int n , k;
    cout << " enter the size of an array:" << endl;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << " enter the value of k:" << endl;
    cin >> k;
    cout << " the minimum height is: " << MinimizetheHeight(arr, k) << endl;
    return 0;
}
// this approach is also known as greedy approach with tc O(nlogn) and sc O(1).
// this approach is also done by sorting the array and then finding the minimum and maximum height after adding and subtracting k from each element.
//  by name of smallest range1 , 2  on leetcode ;
