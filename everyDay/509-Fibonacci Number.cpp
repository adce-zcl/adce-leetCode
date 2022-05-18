// 斐波那契数
// 撕了这块动态规划
#include <vector>
using namespace std;
class Solution 
{
public:
    int fib(int n) 
    {
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return 1;
        }
        // vector<int> dp(n + 1);
        // dp.at(0) = 0;
        // dp.at(1) = 1;
        int dp0 = 0;
        int dp1 = 1;
        int value;
        for (int i = 2; i <= n; ++i)
        {
            // dp.at(i) = dp.at(i - 1) + dp.at(i - 2);
            value = dp0 + dp1;
            dp0 = dp1;
            dp1 = value;
        }
        // return dp.at(n);
        return value;
    }
};