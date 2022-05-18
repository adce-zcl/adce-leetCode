// 增减字符串匹配
#include <vector>
#include <string>
using namespace std;
class Solution 
{
public:
    vector<int> diStringMatch(string s) 
    {
        vector<int> result(s.size() + 1);
        int index = 0;
        int small = 0;
        int big = s.size();
        for (auto &&ch : s)
        {
            if (ch == 'I')
            {
                result.push_back(small++);
            }
            else
            {
                result.push_back(big--);
            }
        }
        result.push_back(small);
        return result;
    }
};