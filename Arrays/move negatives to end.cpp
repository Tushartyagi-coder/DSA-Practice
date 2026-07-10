// all negative numbers to  end of an array
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void movingNegativestoend(vector<int>& arr){
   int n = arr.size();
   int j = 0;
   for( int i = 0 ; i< n ; i++){
    if(arr[i] >= 0){
        swap(arr[i] , arr[j]);
        j++;
    }
   }
}
int main(){
    int n;
    cout << " enter the size of an array:";
    cin >> n;
    vector<int> arr(n);
    cout << " enter the elements of an array:";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    movingNegativestoend(arr);
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
// you can also use two pointer approach one pointer at the start and one at the end and then swap the negative numbers with positive numbers and then move the pointers accordingly.
// tc 0(n) sc 0(1);