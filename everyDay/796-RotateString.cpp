// 旋转字符串
#include <string>
using namespace std;
class Solution 
{
public:
    bool rotateString(string s, string goal) 
    {
        if (s.size() != goal.size())
        {
            return false;
        }
        string new_str = s + s;
        auto it = new_str.find(goal);
        if (it == string::npos)
        {
            return false;
        }
        return true;
    }
};