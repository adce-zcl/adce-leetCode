// 打家劫舍 II
// 动态规划
#include <vector>
using namespace std;
class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        if (nums.size() == 1)
        {
            return nums.at(0);
        }
        if (nums.size() == 2)
        {
            return nums.at(0) > nums.at(1) ? nums.at(0) : nums.at(1);
        }
        vector<int> left(nums.begin(), nums.end() - 1);
        vector<int> right(nums.begin() + 1, nums.end());
        int leftcount = robber(left);
        int rightcount = robber(right);
        return leftcount > rightcount ? leftcount : rightcount;
    }
    int robber(vector<int>& nums)
    {
        if (nums.size() == 1)
        {
            return nums.at(0);
        }
        if (nums.size() == 2)
        {
            return nums.at(0) > nums.at(1) ? nums.at(0) : nums.at(1);
        }
        vector<int> dp(nums.size() + 1, 0);
        dp.at(0) = 0;
        dp.at(1) = nums.at(0);
        dp.at(2) = nums.at(0) > nums.at(1) ? nums.at(0) : nums.at(1);
        for (int i = 3; i <= nums.size(); ++i)
        {
            dp.at(i) = max(dp.at(i - 1), dp.at(i - 2) + nums.at(i - 1));
        }
        return dp.at(nums.size());
    }
};