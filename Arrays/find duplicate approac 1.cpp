// approach 1: sort the array and check for adjacent elements
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findduplicate(vector<int>& arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n ; i++){
        if((arr[i] ^ arr[i + 1]) == 0){
            return arr[i];
        }
    }
    return -1;
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
    int result = findduplicate(arr);
    if(result != -1){
        cout << " the duplicate element is: " << result << endl;
    } else {
        cout << " no duplicate element found." << endl;
    }
    return 0;

}

// this approach has time complexity of O(nlogn) due to sorting and space complexity of O(1) if we sort in place.