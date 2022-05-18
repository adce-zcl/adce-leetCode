// 零钱兑换 II
#include <vector>
using namespace std;
class Solution 
{
public:
    int change(int amount, vector<int>& coins) 
    {
        vector<int> dp(amount + 1);
        dp.at(0) = 1;
        for (int i = 0; i < coins.size(); ++i)
        {
            for (int j = 0; j < dp.size(); ++j)
            {
                if (j >= coins.at(i))
                {
                    dp.at(j) += dp.at(j - coins.at(i));
                }
            }
            
        }
        return dp.at(amount);
    }
};