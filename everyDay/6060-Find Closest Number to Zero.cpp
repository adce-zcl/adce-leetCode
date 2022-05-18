// 找到最接近 0 的数字
#include <vector>
#include <cmath>
using namespace std;
class Solution 
{
public:
    int findClosestNumber(vector<int>& nums) 
    {
        int min = INT_MAX;
        int value;
        for (auto &&v : nums)
        {
            int cur = abs(v - 0);
            if (cur < min)
            {
                min = cur;
                value = v;
            }
            else if (cur == min)
            {
                value = value > v ? value : v;
            }
        }
        return value;
    }
};