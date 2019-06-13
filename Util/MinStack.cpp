#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;


class MinStack {

    void push(int x)
    {
        m_sData.push(x);
        if(m_sMin.top() > x)
        {
            m_sMin.push(x);
        }
        else
        {
            m_sMin.push(m_sMin.top());
        }
    }

    void pop()
    {
        m_sData.pop();
        m_sMin.pop();
    }
    int top()
    {
        return m_sData.top();
    }
    void getMin()
    {
        return m_sMin.top();
    }
    private:
        stack<int> m_sData;
        stack<int> m_sMin;
};

class MinStackV2 {
public:
    /** initialize your data structure here. */
    MinStackV2() {}
    
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= s2.top()) s2.push(x);
    }
    
    void pop() {
        if (s1.top() == s2.top()) s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
    
private:
    stack<int> s1, s2;
};



