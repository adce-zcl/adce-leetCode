// 用栈实现队列
#include <stack>
using namespace std;
class MyQueue 
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() 
    {

    }
    
    void push(int x) 
    {
        s1.push(x);
    }
    int pop() 
    {
        int temp;
        int value;
        while (!s1.empty())
        {
            value = s1.top(); 
            s1.pop();
            s2.push(value);
        }
        s2.pop();
        while (!s2.empty())
        {
            temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
        return value;
    }

    int peek() 
    {
        int temp;
        int value;
        while (!s1.empty())
        {
            value = s1.top(); 
            s1.pop();
            s2.push(value);
        }
        while (!s2.empty())
        {
            temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
        return value;
    }
    bool empty() 
    {
        return s1.empty();
    }
};