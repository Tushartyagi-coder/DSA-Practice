// sum of contiguous subarray with largest sum
//kadane's algorithm
#include<iostream>
#include<vector>
using namespace std;
int largestsubarraysum(vector<int> &arr){
    int maxsum = arr[0];
    int currentsum = arr[0];
    for(int i = 1 ; i < arr.size() ; i++){
        currentsum = max(arr[i] , currentsum + arr[i]);
        maxsum = max(maxsum , currentsum);
    }
    return maxsum;
    // return maxsum; in case of all negative numbers, the maximum sum will be the largest negative number.
}
int main(){
    int n;
    cout << " enter the size of an array:" << endl;
    cin >> n;
    vector<int>arr(n);
    cout << " enter the elements of an array:" << endl;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    int result = largestsubarraysum(arr);
    cout << " the largest sum of contiguous subarray is: " << result << endl;
    return 0;
}
// this approach is also known dp with greedy approach also with constant space  with tc O(n) and sc O(1). 
// we keep track of the current sum and the maximum sum. if the current sum becomes negative, we reset it to the current element.
