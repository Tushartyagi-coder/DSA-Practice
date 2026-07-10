// rotate array by any position
#include<iostream>
#include<vector>
using namespace std;
void reverse(vector<int>& arr , int start , int end){
    while(start < end){
        swap(arr[start] , arr[end]);
        start++;
        end--;
    }
}
int main(){
    int n;
    cout<<"enter the size of an array:"<<endl;
    cin >> n;
    vector<int> arr(n);
    cout << "enter the elements of an array:"<<endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int k;
    cout << "enter the position to rotate the array:"<<endl;
    cin >> k;
    k = k % n; // to handle cases where k > n
    reverse(arr , 0 , n - 1);
    reverse(arr , 0 , k - 1);
    reverse(arr , k , n - 1);
    cout << "the rotated array is:"<<endl;
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
// easy approach with tc O(n) and sc O(1) is to use the reverse method. First, reverse the whole array, then reverse the first k elements, and finally reverse the remaining n-k elements.