// merge two sorted array with gap method;git add .
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void mergetwosortedarray(vector<int> &arr1 , vector<int> &arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    int gap = ceil((n1 + n2) / 2.0);
    while(gap > 0){
        int left = 0 ;
        int right = gap;
        while( right < n1 + n2){
            // when both lies on arr1;
            if( left < n1 && right <n1){
                if(arr1[left] > arr1[right]){
                    swap(arr1[left] , arr1[right]);
                }
            }
            // whrn one lies in arr1 and second lies in arr2;
            else if( left < n1 && right >= n1){
                if(arr1[left] > arr2[right - n1]){
                    swap(arr1[left] , arr2[right - n1]);
                }
            } 
            else{ // when both lies in arr2;
                if( arr2[left - n1] > arr2[right - n1])  swap( arr2[left - n1] , arr2[right - n1]);
            }
            right++;
            left++;
        }
        if(gap == 1) break;
        gap = ceil(gap / 2.0);

    }
     for (int i = 0; i < n2; i++) {
            arr1[n1 + i] = arr2[i];
        }
}

// time complexity =  O((n + m) log(n + m))
// space complexity = O(1) no use of extra spaces;

int main() {
    int n1, n2;

    cout << "Enter size of first array: ";
    cin >> n1;

    cout << "Enter size of second array: ";
    cin >> n2;

    vector<int> arr1(n1);
    vector<int> arr2(n2);

    cout << "Enter elements of first sorted array:\n";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter elements of second sorted array:\n";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    mergetwosortedarray(arr1, arr2);

    cout << "Merged Array:\n";
    for (int i = 0; i < n1 + n2; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    return 0;
}