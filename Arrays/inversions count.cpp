#include<bits/stdc++.h>
using namespace std;

int merge( vector<int> &arr,int left , int mid , int right){
    int count = 0;
    vector<int>temp;
    int i = left;
    int j = mid + 1;
    while( i <= mid && j <= right ){
        if( arr[i] <= arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
            count += ( mid - i + 1);
        }
    }
    while( i <= mid ) temp.push_back(arr[i++]);
    while( j <= right ) temp.push_back(arr[j++]);
    for( int k = left ; k <= right ; k++ ){
        arr[k] = temp[k - left];
    }
    return count;
}
int mergesort(vector<int> &arr , int left , int right){
    int count = 0;
    if( left >= right) return 0;
     int mid = ( left + right) / 2;
    count = count + mergesort(arr , left , mid);
    count = count + mergesort(arr , mid + 1 , right);
    count = count + merge(arr , left , mid , right);
    return count;
}
// Approach Name = Divide and Conquer
// sc : O(n) + O(log n) = O(n)
// tc : O(n log n)
int main(){
    vector<int>arr = {2, 7, 4, 8 , 1, 3};
    int n = arr.size();
    int ans = mergesort(arr , 0 , n - 1);
    cout << "Number of inversions are : " << ans << endl; // 7
        return 0;
}