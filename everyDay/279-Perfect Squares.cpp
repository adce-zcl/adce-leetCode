// 完全平方数
#include <vector>
#include <climits>
using namespace std;
class Solution 
{
public:
    int numSquares(int n) 
    {
        vector<int> dp(n + 1, INT_MAX);
        dp.at(0) = 0;
        for (int i = 1; i*i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (j >= i*i)
                {
                    dp.at(j) = min(dp.at(j), dp.at(j - i * i) + 1);
                }
            }
        }
        return dp.at(n);
    }
};