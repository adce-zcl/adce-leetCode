// 目标和
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;
class Solution 
{
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum - target) % 2 != 0)
        {
            return 0;
        }
        if (abs(target) > sum)
        {
            return 0;
        }
        
        // 求所有和为resultSum的个数
        int resultSum = (sum - target) / 2;
        int count = 0;
        vector<int> dp(resultSum + 1, 0);
        dp.at(0) = 1;   // 填满容量为0的背包，有1种方法，就是填0
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = resultSum; j >= 0; --j)
            {
                if (j >= nums.at(i))
                {
                    // 填满容量为j的方法的个数应该等于所有的填满j-nums.at(i)之和
                    // 因为是滚动数组，数据从上一层拷贝下来，所以dp.at(j) 就代表之前的dp(j-nums[i])之和
                    dp.at(j) = dp.at(j) + dp.at(j - nums.at(i));
                }
                else
                {
                    break;
                }
            }
            
        }
        return dp.at(target);
    }
};