// 平方数之和
// 双指针法
#include <cmath>
class Solution 
{
public:
    bool judgeSquareSum(int c) 
    {
        int left = 0;
        int right = (int)sqrt(c);
        while (left <= right)
        {
            if (left * left + right * right == c)
            {
                return true;
            }
            else if (left * left + right * right < c)
            {
                ++left;
            }
            else if (left * left + right * right > c)
            {
                --right;
            }
        }
        return false;
    }
};
