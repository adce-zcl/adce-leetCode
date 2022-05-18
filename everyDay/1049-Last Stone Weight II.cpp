// 最后一块石头的重量 II
#include <vector>
#include <numeric>
using namespace std;
class Solution 
{
public:
    int lastStoneWeightII(vector<int>& stones) 
    {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int bagSum = sum / 2;
        vector<int> dp(bagSum + 1, 0);
        for (int i = 0; i < stones.size(); ++i)
        {
            for (int j = bagSum; j >= 0; --j)
            {
                if (j >= stones.at(i))
                {
                    dp.at(j) = max(dp.at(j), dp.at(j - stones.at(i)) + stones.at(i));
                }
                else
                {
                    break;
                }
            }
        }
        int value = sum - dp.at(bagSum) - dp.at(bagSum);
        return value;
    }
};