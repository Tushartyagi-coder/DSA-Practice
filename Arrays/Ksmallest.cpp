// simple sorting algorithm to find the kth smallest element in an array
#include<iostream>
using namespace std;
void bubblesort( int arr[] , int n , int k){
    for(int i = 0; i< n - 1; i++){
        for(int j = 0 ; j < n - i - 1 ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(){
   int  n ;
   cout << "Enter the size of array: ";
   cin >> n;

   int arr[n];
   cout << "Enter the elements of array: ";
   for(int i = 0; i < n; i++){
       cin >> arr[i];
   }
   int k;
   cout << "Enter the value of k: ";
   cin >> k;
   bubblesort(arr, n, k);
    cout << "The " << k << "th smallest element is: " << arr[k-1] << endl;
    return 0;
}
// u can aslo use stl files first sort the array and then return the kth element from the sorted array by doing arr[k-1];