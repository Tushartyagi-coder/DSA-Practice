// sort 0 1 2 in an array;
#include<iostream>
using namespace std;
void sort012( int arr[] , int n){
    int start= 0;
    int mid = 0;
    int end = n-1;
    while(mid <= end){
        if(arr[mid] == 0){
            swap(arr[start++] , arr[mid++]);
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid] , arr[end--]);
        }
    }
}
int main(){
    int n;
    cout << " enter the size of an array:";
    cin >> n;
    int arr[n];
    cout << " enter the elements of an array:";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort012(arr, n);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
// you can also use by declaring three variables count0, count1, count2 and then traverse the array and count the number of 0's, 1's and 2's and then fill the array with those counts.
// tc 0(n) sc 0(1);