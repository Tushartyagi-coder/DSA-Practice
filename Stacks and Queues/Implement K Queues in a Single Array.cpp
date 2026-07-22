//Approach Name: K Queues in a Single Array (Dynamic Slot Allocation)
//Pattern Name: Free List / Memory Pool Pattern
// SC = o(N + K);
// TC = O(1);
#include<bits/stdc++.h>
using namespace std;
class kqueues{
    private:
    int N;
    int K;
    int *arr;
    int *front;
    int *rear;
    int freespot;
    int *next;
    public:
    kqueues( int n , int k){
        N = n;
        K = k;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        freespot = 0;
        next = new int[n];
        for( int i = 0;i < n ;i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
        for(int i = 0;i <k;i++){
            front[i] = -1;
            rear[i] = -1;
        }
    }
      void enqueue(int x , int i){
        if( freespot == -1){
            return;
        }
        int index = freespot;
        freespot = next[index];
        if( front[i] == -1){
                front[i] = index;
        }
        else{
            next[rear[i]] = index;
        }
        rear[i] = index;
        next[index] = -1;
        arr[index] = x;
      }
      int dequeues( int i){
        if(front[i] == -1){
            return -1;
        }
     int index = front[i];
     front[i] = next[index];
     next[index] = freespot;
     freespot = index; 
     return arr[index];
      }
    bool isEmpty(int i) {
        return front[i] == -1;
    }

    bool isFull() {
       return freespot == -1;
    }
    };
    int main() {
    kqueues kq(10, 3); // 10 slots, 3 queues

    kq.enqueue(10, 0);
    kq.enqueue(20, 1);
    kq.enqueue(30, 2);
    kq.enqueue(40, 2);

    cout << kq.dequeues(0) << endl; // 10
    cout << kq.dequeues(1) << endl; // 20
    cout << kq.dequeues(2) << endl; // 30
    cout << kq.dequeues(2) << endl; // 40

    return 0;
}