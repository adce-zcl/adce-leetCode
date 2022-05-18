//  组合总和 Ⅳ
#include <vector>
using namespace std;
class Solution 
{
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<int> dp(target + 1, 0);
        dp.at(0) = 1;
        for (int j = 1; j <= target; ++j)
        {
            for (int i = 0; i < nums.size(); ++i)
            {
                if (j > nums.at(i))
                {
                    dp.at(j) += dp.at(j - nums.at(i));
                }
            }
        }
        return dp.at(target);
    }
};