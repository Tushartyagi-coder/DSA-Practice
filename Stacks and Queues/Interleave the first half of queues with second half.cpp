// problem name = Interleave First Half with Second Half of Queue;
// Pattern: Queue + Stack manipulation;
// Approach: Two Stack Reversal;
// SC: O(n) — stacks use ki hain;
// TC: O(n) — har element constant baar touch hua;

#include <bits/stdc++.h>
using namespace std;
 void rearrangeQueue(queue<int> &q) {
        int n = q.size();
        int half = n / 2;
        stack<int>s;
        for(int i = 0 ; i < half ; i++){
            int value = q.front();
            q.pop();
            s.push(value);
        }
        // Step 3 - reverse karke push (do stack trick)
stack<int> s2;
while(!s.empty()){
    s2.push(s.top());
    s.pop();
}
while(!s2.empty()){
    q.push(s2.top());
    s2.pop();
}
// Step 4
for(int i = 0; i < half; i++){
    s.push(q.front());
    q.pop();
}
stack<int>s3;
while(!s.empty()){
    s3.push(s.top());
    s.pop();
}

// Step 5
while(!s3.empty()){
    q.push(q.front());  // first half ka element pehle
    q.pop();
    q.push(s3.top());    // second half ka element baad mein
    s3.pop();
}
    }
int main(){
    int n;
    cin >> n;
    queue<int> q;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        q.push(x);
    }
    
    rearrangeQueue(q);
    
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}