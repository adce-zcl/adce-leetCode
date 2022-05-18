// 最佳买卖股票时机含冷冻期
// 0.不持股且不在冷冻期
// 1.不持股且在冷冻期
// 2.持股
#include <vector>
using namespace std;
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int size = prices.size();
        if (size <= 1)
        {
            return 0;
        }
        vector<vector<int>> dp(size, vector<int>(3, 0));
        dp.at(0).at(0) = 0;
        dp.at(0).at(1) = 0;
        dp.at(0).at(2) = -prices.at(0);
        for (int i = 1; i < size; ++i)
        {
            dp.at(i).at(2) = max(dp.at(i - 1).at(2), dp.at(i - 1).at(0) - prices.at(i));
            dp.at(i).at(1) = dp.at(i - 1).at(2) + prices.at(i);
            dp.at(i).at(0) = max(dp.at(i - 1).at(0), dp.at(i - 1).at(1));
        }
        return max(dp.at(size - 1).at(0), dp.at(size - 1).at(1));
    }
};