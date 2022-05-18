// 最大子数组和
// 动态规划
#include <vector>
using namespace std;
class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int maxSum = nums.at(0);
        int pre = 0;
        for (auto &&num : nums)
        {
            pre = max(pre + num, num);
            maxSum = max(maxSum, pre);
        }
        return maxSum;
    }
    int maxSubArray(vector<int>& nums) 
    {
        int size = nums.size();
        vector<int> dp(size, 0);
        dp.at(0) = nums.at(0);
        int maxSum = dp.at(0);
        for (int i = 1; i < size; ++i)
        {
            dp.at(i) = max(dp.at(i - 1) + nums.at(i), nums.at(i));
            if (dp.at(i) > maxSum)
            {
                maxSum = dp.at(i);
            }
        }
        return maxSum;
    }
};