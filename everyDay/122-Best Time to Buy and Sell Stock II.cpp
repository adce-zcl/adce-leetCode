// 买卖股票的最佳时机 II
// 贪心算法
#include <vector>
using namespace std;
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int result;
        for (size_t i = 1; i < prices.size(); ++i)
        {
            result += max(prices.at(i) - prices.at(i - 1), 0);
        }
        return result;
    }
    int maxProfit(vector<int>& prices) 
    {
        int size = prices.size();
        vector<vector<int>> value(size, vector<int>(2));
        value.at(0).at(0) = 0; // 当前不买股票的最大钱
        value.at(0).at(1) = -prices.at(0);  // 当前买股票的最大钱
        for (int i = 1; i < size; ++i)
        {
            value.at(i).at(0) = max(value.at(i - 1).at(0), value.at(i - 1).at(1) + prices.at(i));
            value.at(i).at(1) = max(value.at(i - 1).at(1), value.at(i - 1).at(0) - prices.at(i));
        }
        return value.at(size - 1).at(0);
    }
};