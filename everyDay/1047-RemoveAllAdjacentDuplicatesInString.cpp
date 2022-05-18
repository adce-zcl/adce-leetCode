//  删除字符串中的所有相邻重复项
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
class Solution
{
public:
    string removeDuplicates(string s) 
    {
        stack<char> my_stack;
        string value;
        for (auto &&ch : s)
        {
            if (!my_stack.empty() && ch == my_stack.top())
            {
                my_stack.pop();
                continue;
            }
            my_stack.push(ch);
        }
        while (!my_stack.empty())
        {
            value += my_stack.top();
            my_stack.pop();
        }
        reverse(value.begin(), value.end());
        return value;
    }
};