// 买卖股票的最佳时机 III
// 动态规划
// 0：没有操作
// 1：第一次买入
// 2：第一次卖出
// 3：第二次买入
// 4：第二次卖出
// dp[i][j],第i天第j种状态手中所持有的钱
#include <vector>
using namespace std;
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int size = prices.size();
        vector<vector<int>> dp(size + 1, vector<int>(5));
        dp.at(0).at(0) = 0;
        dp.at(0).at(1) = -prices.at(0);
        dp.at(0).at(2) = 0;
        dp.at(0).at(3) = -prices.at(0);
        dp.at(0).at(4) = 0;
        for (int i = 1; i < size; ++i)
        {
            dp.at(i).at(0) = dp.at(i - 1).at(0);    // 无操作就是无操作
            dp.at(i).at(1) = max(dp.at(i - 1).at(1), dp.at(i - 1).at(0) - prices.at(i));
            dp.at(i).at(2) = max(dp.at(i - 1).at(2), dp.at(i - 1).at(1) + prices.at(i));
            dp.at(i).at(3) = max(dp.at(i - 1).at(3), dp.at(i - 1).at(2) - prices.at(i));
            dp.at(i).at(4) = max(dp.at(i - 1).at(4), dp.at(i - 1).at(3) + prices.at(i));
        }
        return dp.at(size - 1).at(4);
    }
};