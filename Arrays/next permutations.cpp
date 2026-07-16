// next permutation
// three step in place algorithm 
#include <bits/stdc++.h>
using namespace std;
void nextpermutations(vector<int> &nums){
    int n = nums.size();
    int index = -1;
    for( int i = n-2 ; i >= 0 ; i--){
        if(nums[i] < nums[i + 1]){
            index = i;
            break;
        }
    }
    if( index != -1){
        for( int j = n-1; j >= index+1; j--){
            if(nums[j] > nums[index]){
                swap(nums[j] , nums[index]);
                break;
            }
        }
    }
    reverse(nums.begin() + index + 1 , nums.end());
}
// tc = O(n);
// sc = O(1);


int main() {
    int n;
    cout << "enter the size of an array :" << endl;
    cin >> n;

    vector<int> nums(n);
cout << "enter the elements for permutation:"<<endl;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    nextpermutations(nums);

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
