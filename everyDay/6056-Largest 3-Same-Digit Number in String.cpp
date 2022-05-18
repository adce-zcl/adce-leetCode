// 字符串中最大的 3 位相同数字
#include <string>
using namespace std;
class Solution 
{
public:
    string largestGoodInteger(string num) 
    {
        string value = "";
        int start = 0;
        int end = start + 3;
        while (end <= num.size())
        {
            string cur(num.begin() + start, num.begin() + end);
            int i;
            for (i = 1; i < 3; ++i)
            {
                if (cur.at(i) != cur.at(i - 1))
                {
                    break;
                }
            }
            if (i == 3)
            {
                value = value > cur ? value : cur;
            }
            start++;
            end = start + 3;
        }
        return value;
    }
};