// 找到一个数字的 K 美丽值
#include <string>
using namespace std;
class Solution 
{
public:
    int divisorSubstrings(int num, int k) 
    {
        string str = to_string(num);
        int count = 0;
        int start = 0, end = start + k;
        while (end <= str.size())
        {
            string temp(str.begin() + start, str.begin() + end);
            int tempnum = stoi(temp);
            if (tempnum != 0 && num % tempnum == 0)
            {
                ++count;
            }
            ++start;
            end = start + k;
        }
        return count;
    }
};