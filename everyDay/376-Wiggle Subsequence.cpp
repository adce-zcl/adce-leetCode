// 摆动序列
#include <vector>
using namespace std;

class Solution 
{
public:
    // 贪心算法
    int wiggleMaxLength(vector<int>& nums) 
    {
        if (nums.size() == 1 || (nums.size() == 2 && nums.at(0) != nums.at(1)))
        {
            return nums.size();
        }
        int count = 0;  // 需要减少的数量
        int cur_diff = 0;
        int pre_diff = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            cur_diff = nums.at(i + 1) - nums.at(i);
            if ((cur_diff > 0 && pre_diff <= 0) || (cur_diff < 0 && pre_diff >= 0))
            {
                ++count;
                pre_diff = cur_diff;
            }
        }
        return count + 1;
    }
};