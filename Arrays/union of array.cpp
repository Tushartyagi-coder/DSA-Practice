// union of arrays with duplicates removed
// must condition is that the array is sorted in ascending order
#include<iostream>
#include<vector>
using namespace std;
vector<int> unionofarray(vector<int>arr1 , vector<int>arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0 , j = 0;
    vector<int>ans;
    while(i < n1 && j < n2){
        if(arr1[i] <= arr2[j]){
if(ans.empty() || ans.back() != arr1[i])
            ans.push_back(arr1[i]);
            i++;
        }
        else{
if(ans.empty() || ans.back() != arr2[j])
            ans.push_back(arr2[j]);
            j++;
        }
    }
    while(i < n1){
if(ans.empty() || ans.back() != arr1[i])
        ans.push_back(arr1[i]);
        i++;
    }
    while(j < n2){
if(ans.empty() || ans.back() != arr2[j])
        ans.push_back(arr2[j]);
        j++;
    }
    return ans;
}
int main(){
    int n1 , n2;
    cout << " enter the size of first array:" << endl;
    cin >> n1;
    vector<int>arr1(n1);
    cout << " enter the elements of first array:" << endl;
    for(int i = 0; i < n1; i++){
        cin >> arr1[i];
    }

     cout << " enter the size of second array:" << endl;
    cin >> n2;
    vector<int>arr2(n2);
    cout << " enter the elements of second array:" << endl;
    for(int i = 0; i < n2; i++){
        cin >> arr2[i];
    }
    vector<int>result = unionofarray(arr1 , arr2);
    cout << " the union of two arrays is:" << endl;
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;

}
// tc 0(n1+n2) sc 0(n1+n2);
// just two pointers approach
// if array is not sorted then this approach will not work and we have to use set and sort the array and then return the union of two arrays with duplicates removed.
