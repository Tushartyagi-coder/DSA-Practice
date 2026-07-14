// // approach 1: sort the array and check for adjacent elements
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// int findduplicate(vector<int>& arr){
//     int n = arr.size();
//     sort(arr.begin(), arr.end());
//     for(int i = 0; i < n ; i++){
//         if((arr[i] ^ arr[i + 1]) == 0){
//             return arr[i];
//         }
//     }
//     return -1;
// }
// approach 2: using floyd's cycle detection to find duplicate
int findduplicate(vector<int>& arr){
    int slow = arr[0];
    int fast = arr[0];
    do{
        slow = arr[slow];
        fast = arr[arr[fast]];

    } while( slow != fast);
    fast = arr[0];
    while( slow != fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}
// this approach has time complexity of O(n) and space complexity of O(1). we use two pointers, slow and fast. slow moves one step at a time and fast moves two steps at a time. if there is a cycle, they will meet at some point. then we reset fast to the start and move both pointers one step at a time until they meet again. the meeting point is the duplicate element.
int main(){
    int n;
    cout << " enter the size of an array:" << endl;
    cin >> n;
    vector<int>arr(n);
    cout << " enter the elements of an array:" << endl;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    int result = findduplicate(arr);
    if(result != -1){
        cout << " the duplicate element is: " << result << endl;
    } else {
        cout << " no duplicate element found." << endl;
    }
    return 0;

}

// // this approach has time complexity of O(nlogn) due to sorting and space complexity of O(1) if we sort in place.

