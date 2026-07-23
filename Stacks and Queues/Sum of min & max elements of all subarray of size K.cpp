// pattern name : Fixed Size Sliding Window using Monotonic Deque;
// approach name : Maintain two monotonic deques;
// TC = O(n);
// SC = O(k);
#include<bits/stdc++.h>
using namespace std;
int solve(int *arr , int n , int k){
    deque<int>maxi;
    deque<int>mini;
     int ans  = 0;
    for( int i = 0 ;  i < k ; i++){
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while( !mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
        

    }
    ans = ans + arr[maxi.front()] + arr[mini.front()];
   
    for( int i = k ; i < n ;i++){
        // removal
        while(!maxi.empty() &&  i - maxi.front() >= k){
            maxi.pop_front();

        }
        while(!mini.empty() && i - mini.front() >=k){
            mini.pop_front();
        }
        // addition;
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
        maxi.pop_back();
        }

        while( !mini.empty() && arr[mini.back()] >= arr[i]){
        mini.pop_back();
        }
        maxi.push_back(i);
        mini.push_back(i);
          ans = ans + arr[maxi.front()] + arr[mini.front()];


    }
    return ans;

}
// Interview Tip
//Agar interviewer pooche:
//Deque me value store kyu nahi ki, index kyu store kiya?
// Answer: 
// Hume pata hona chahiye ki element current window me hai ya nahi.
// Window se bahar hua to remove karna hota hai.
// Sirf value store karoge to uski position nahi pata chalegi.
// Isliye deque me indices store karte hain aur values ko arr[index] se access karte hain.
// Ye question interviews me kaafi baar poocha jata hai.
int main() {
    int arr[7] = {2 , 5 , -1 , 7 , -3 , -1 , -2};
    int k = 4;
    cout << solve(arr , 7 , 4) << endl;

    return 0;
}