// 相邻字符不同的最长路径
#include <vector>
#include <string>
using namespace std;
class Solution 
{
private:
    char pre = '1';
    int result = 0;
    void func(vector<int>& parent, string &s, int index, int length)
    {
        if (index == -1 || s.at(index) == pre)
        {
            result = result > length ? result : length;
            return;
        }
        pre = s.at(index);
        index = parent.at(index);
        func(parent, s, index, length + 1);
        return;
    }

public:
    int longestPath(vector<int>& parent, string s) 
    {
        for (size_t i = 0; i < s.size(); ++i)
        {
            func(parent, s, i, 0);
        }
        return result;
    }
};