//  买卖股票的最佳时机含手续费
#include <vector>
using namespace std;
class Solution 
{
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        // vector<vector<int>> dp(2, vector<int>(2));
        // dp[0][0] = 0;   // 手中没有股票
        // dp[0][1] = -prices.at(0);   // 手中有股票
        int shell = 0;
        int had = -prices.at(0);
        for (int i = 1; i < n; ++i)
        {
            shell = max(shell, had + prices.at(i) - fee);
            had = max(had, shell - prices.at(i));
            // dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices.at(i) - fee);
            // dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices.at(i));
        }
        // return dp[n - 1][0];
        return shell;
    }
    // 动态规划
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(2));
        dp[0][0] = 0;   // 手中没有股票
        dp[0][1] = -prices.at(0);   // 手中有股票
        for (int i = 1; i < n; ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices.at(i) - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices.at(i));
        }
        return dp[n - 1][0];
    }
};