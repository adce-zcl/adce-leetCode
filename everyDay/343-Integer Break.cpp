// 整数拆分
#include <vector>
#include <iostream>
using namespace std;
class Solution 
{
public:
    int integerBreak(int n) 
    {
        vector<int> dp(n + 1);
        dp.at(2) = 1;
        for (int i = 3; i <= n; ++i)
        {
            for (int j = 1; j < i; ++j)
            {
                // 每次都要有dp.at(i),因为j循环每次都可能更新dp[i]
                dp.at(i) = max(dp.at(i), max(j * (i - j), j * dp.at(i - j)));
                // dp.at(i) = max(j * (i - j), j * dp.at(i - j));
                cout << dp.at(i) << endl;
            }
        }
        return dp.at(n);
    }
};
int main()
{
    Solution s;
    s.integerBreak(4);
    system("pause");
}