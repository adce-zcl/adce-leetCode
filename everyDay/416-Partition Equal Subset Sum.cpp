// 分割等和子集
// 01背包问题
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)   // 不是偶数
        {
            return false;
        }
        int bagSum = sum / 2;   // 背包的容量
        vector<int> dp(bagSum + 1, 0);
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = dp.size() - 1; j >= 0; --j)
            {
                if (j >= nums.at(i))
                {
                    dp.at(j) = max(dp.at(j), dp.at(j - nums.at(i)) + nums.at(i));
                }
            }
        }
        if (dp.at(bagSum) == bagSum)
        {
            return true;
        }
        return false;
    }
};