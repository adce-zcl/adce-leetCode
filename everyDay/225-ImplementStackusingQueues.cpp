// 用队列实现栈
#include <queue>
using namespace std;
class MyStack 
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() 
    {
    }
    
    void push(int x) 
    {
        q1.push(x);
    }
    
    int pop() 
    {
        int value;
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        value = q1.front();
        q1.pop();
        while (q2.size() != 0)
        {
            q1.push(q2.front());
            q2.pop();
        }
        return value;
    }
    
    int top() 
    {
        int value;
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        value = q1.front();
        q1.pop();
        q2.push(value);
        while (q2.size() != 0)
        {
            q1.push(q2.front());
            q2.pop();
        }
        return value;        
    }
    
    bool empty() 
    {
        return q1.empty();
    }
};