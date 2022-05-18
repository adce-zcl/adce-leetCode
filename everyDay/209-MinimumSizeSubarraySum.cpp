// 长度最小的子数组
// 滑动窗口

#include <vector>
using namespace std;
class Solution 
{
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int left = 0, right = 0;
        int min_num = nums.size() + 1;
        int current_num = 0;
        int sum = 0;
        for (right; right < nums.size(); ++right)
        {
            sum += nums.at(right);
            ++current_num;
            while (sum >= target)
            {
                min_num = current_num < min_num ? current_num : min_num;
                sum -= nums.at(left);
                --current_num;
                ++left;
            }
        }
        if(min_num > nums.size())
        {
            return 0;
        }
        else
        {
            return min_num;
        }
    }
};