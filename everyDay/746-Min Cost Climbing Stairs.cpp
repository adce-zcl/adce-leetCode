// 使用最小花费爬楼梯
#include <vector>
using namespace std;
class Solution 
{
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        vector<int> minCosts(cost.size());
        minCosts.at(0) = cost.at(0);
        minCosts.at(1) = cost.at(1);
        for (int i = 2; i < cost.size(); ++i)
        {
            minCosts.at(i) = min(minCosts.at(i - 1), minCosts.at(i - 2)) + cost.at(i);
        }
        int value = min(minCosts.at(cost.size() - 1), minCosts.at(cost.size() - 2));
        return value;
    }
};