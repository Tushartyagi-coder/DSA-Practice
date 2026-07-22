// Approach Name: N Stacks in a Single Array (Dynamic Slot Allocation)
// Pattern Name: Free List / Memory Pool Pattern
// SC = O( S + N );
// TC = O(1);
#include <bits/stdc++.h> 
using namespace std;
class NStack
{
    int *arr;
    int *top;
    int * next;
    int n , s;
    int freespot;
public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
      n = N;
      s = S;
      arr = new int[s];
      top = new int[n];
      next = new int[s];
      // top initialise
      for( int i = 0; i < n ; i++){
          top[i] = -1;
      }
      // next initailaize;
      for( int i = 0 ; i < s ; i++){
          next[i] = i + 1 ; 
      }
        // update last wala
          next[s-1] = -1;
          freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
       if( freespot == -1){
           return false;
       }
       int index = freespot;
       freespot = next[index];
       arr[index] = x;
       next[index] = top[m-1];
       top[m-1] = index;

       return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if( top[m-1] == -1){
            return -1;
        }
      int  index = top[m-1];
      int value = arr[index];
       top[m-1] = next[index];
       next[index] = freespot;
       freespot = index;
       return value;
    
    }
    
};
int main(){
       NStack ns(3, 6); // 3 stacks, 6 slots

    ns.push(10, 1);
    ns.push(20, 1);
    ns.push(30, 2);
    ns.push(40, 3);

    cout << ns.pop(1) << endl; // 20
    cout << ns.pop(1) << endl; // 10
    cout << ns.pop(2) << endl; // 30
    cout << ns.pop(3) << endl; // 40

    return 0;
}