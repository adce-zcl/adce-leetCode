// 逆波兰表达式求值
#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution 
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> s;
        for (size_t i = 0; i < tokens.size(); ++i)
        {
            string current = tokens.at(i);
            if (current == "+")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int sum = a + b;
                s.push(sum);
            }
            else if (current == "-")
            {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                int sub = a - b;
                s.push(sub);
            }
            else if (current == "*")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int mult = a * b;
                s.push(mult);
            }
            else if (current == "/")
            {
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                int divi = a / b;
                s.push(divi);
            }
            else
            {
                s.push(stoi(current));
            }
        }
        return s.top();
    }
};
int main()
{
    Solution s;
    vector<string> v{"2", "1", "+", "3", "*"};
    s.evalRPN(v);
}