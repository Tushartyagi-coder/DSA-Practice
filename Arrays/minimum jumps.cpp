// minimum jumps
// counts jumps to reach the end of an array
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int minimumjumps(vector<int> &arr){
    int n = arr.size();
     if(arr[0] == 0){
        return -1;
     }
    if( n == 1){
        return 0;
    }
    int farpoint = 0;
    int currentend = 0;
    int jumps = 0;
    for( int i = 0; i < n - 1; i++){
        farpoint = max(farpoint , i + arr[i]);
        if( i == currentend){
            if(farpoint == currentend){
                return -1;
            }
            jumps++;
            currentend = farpoint;
        }
    }
    return jumps;
}
int main(){
    int n;
    cout<<" enter the size of an array:" << endl;
    cin >> n;
    vector<int> arr(n);
    cout << " enter the elements of an array:" << endl;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int result = minimumjumps(arr);
    if(result == -1){
        cout << " it is not possible to reach the end of the array." << endl;
    }
    else{
        cout << " the minimum jumps to reach the end of the array is: " << result << endl;
    }
}
// this approach is also known as greedy approach with tc O(n) and sc O(1).
// we keep track of the farthest point we can reach and the current end of the jump. when we reach the current end, we increment the jump count and update the current end to the farthest point we can reach.
// this approach is also done by using bfs with tc O(n) and sc O(n).
// so good question with edges cases heandled easily.