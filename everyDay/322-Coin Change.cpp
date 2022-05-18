// 零钱兑换
#include <vector>
#include <climits>
using namespace std;
class Solution 
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp.at(0) = 0;
        for (int i = 0; i < coins.size(); ++i)
        {
            for (int j = 1; j <= amount; ++j)
            {
                if (j >= coins.at(i) && dp.at(j - coins.at(i)) != INT_MAX)
                {
                    dp.at(j) = min(dp.at(j), dp.at(j - coins.at(i)) + 1);
                }
            }
        }
        if (dp.at(amount) == INT_MAX)
        {
            return -1;
        }
        return dp.at(amount);
    }
};