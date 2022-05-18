// 买卖股票的最佳时机
#include <vector>
using namespace std;
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int minPrices = prices.at(0);
        int maxSubPrices = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            maxSubPrices = max(maxSubPrices, prices.at(i) - minPrices);
            minPrices = min(minPrices, prices.at(i));
        }
        return maxSubPrices;
    }
    int maxProfit(vector<int>& prices) 
    {
        int size = prices.size();
        vector<vector<int>> value(size, vector<int>(2));
        value.at(0).at(0) = 0;  // 当前不持有股票的钱
        value.at(0).at(1) = -prices.at(0);  // 当前持有股票的钱
        for (int i = 1; i < size; ++i)
        {
            value.at(i).at(0) = max(value.at(i - 1).at(0), value.at(i - 1).at(1) + prices.at(i));
            value.at(i).at(1) = max(value.at(i - 1).at(1), value.at(i - 1).at(0) - prices.at(i));
        }
        return value.at(size - 1).at(0);
    }
};