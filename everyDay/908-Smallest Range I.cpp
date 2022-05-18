// 最小差值 I
#include <vector>
#include <cstdlib>
using namespace std;
class Solution 
{
public:
    int smallestRangeI(vector<int>& nums, int k) 
    {
        int min_num = INT_MAX;
        int max_num = INT_MIN;
        int value;
        for (auto &&num : nums)
        {
            min_num = min_num < num ? min_num : num;
            max_num = max_num > num ? max_num : num;
        }

        if (max_num - min_num <= 2 * k)
        {
            value = 0;
        }
        else
        {
            value = (max_num - k) - (min_num + k);
        }
        return value;
    }
};