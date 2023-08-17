#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> s;        
    MyQueue() {
    }
    
    void push(int x) {
        if (s.empty()) {
            s.push(x);
        }
        else {
            vector<int> v;
            while (!s.empty()) {
                v.push_back(s.top());
                s.pop();
            }
            s.push(x);
            for (int i=v.size()-1;i>=0;i--) {
                s.push(v[i]);
            }            
        }
    }
    
    int pop() {
        
    }
    
    int peek() {
        
    }
    
    bool empty() {
        
    }
};
