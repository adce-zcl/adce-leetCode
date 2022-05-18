// 买卖股票的最佳时机 IV
// 和123一样，只不过需要区分奇偶数
#include <vector>
using namespace std;
class Solution 
{
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int size = prices.size();
        if (size <= 1)
        {
            return 0;
        }
        vector<vector<int>> dp(size, vector<int>(2 * k + 1, 0));
        // 初始化，所有买入操作都是-prices.at(0)
        for (int j = 1; j < 2*k; j+=2)
        {
            dp.at(0).at(j) = -prices.at(0);
        }
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < 2*k - 1; j+=2)
            {
                dp.at(i).at(j + 1) = max(dp.at(i - 1).at(j + 1), dp.at(i - 1).at(j) - prices.at(i));
                dp.at(i).at(j + 2) = max(dp.at(i - 1).at(j + 2), dp.at(i - 1).at(j + 1) + prices.at(i));
            }
        }
        return dp.at(size - 1).at(2 * k);
    }
};