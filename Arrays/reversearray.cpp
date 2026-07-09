#include<iostream>
using namespace std;
void reversearray(int arr[] , int n){
    // so function is void no return value
    int start = 0;
    int end = n - 1;
    while(start < end){
        swap(arr[start] , arr[end]);
        start++;
        end--;
    }
}
int main(){
    int arr[5] = {1 , 2, 3 ,4 ,5};
    reversearray( arr , 5);
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    return 0;
}