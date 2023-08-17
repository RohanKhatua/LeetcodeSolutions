#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    stack<int> s1;
    stack<int> s2;

    MinStack()
    {
       s1= {};
       s2 = {};
    }

    void push(int val)
    {
        s1.push(val);
        if (!s2.empty()) {
            val = s2.top();
        }
        s2.push(val);
    }

    void pop()
    {
        s1.pop();
        s2.pop();
    }

    int top()
    {
        return s1.top();
    }

    int getMin()
    {
       return s2.top();
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
