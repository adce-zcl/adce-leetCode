// 最长递增子序列
// 动态规划
#include <vector>
using namespace std;
class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int size = nums.size();
        vector<int> dp(size, 1);
        int maxlength = 1;
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums.at(i) > nums.at(j))
                {
                    dp.at(i) = max(dp.at(i), dp.at(j) + 1);
                }
            }
            if (dp.at(i) > maxlength)
            {
                maxlength = dp.at(i);
            }
        }
        return maxlength;
    }
};