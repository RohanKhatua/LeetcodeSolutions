#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    priority_queue<int, vector<int>,greater<int>> pq;
    stack<int> s;
    MinStack()
    {
        pq = {};
        s = {};
    }

    void push(int val)
    {
        s.push(val);
        pq.push(val);      
    }

    void pop()
    {
        int ele = s.top();
        s.pop();
        stack<int> copy = s;
        pq = priority_queue<int, vector<int>, greater<int>>();
        while (!copy.empty()) {
            pq.push(copy.top());
            copy.pop();
        }
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return pq.top();
    }
};

int main()
{
    MinStack *m = new MinStack();
    m->push(5);
    m->push(4);
    m->pop();
    cout << m->getMin();
}
