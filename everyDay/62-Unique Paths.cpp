// 不同路径
#include <vector>
using namespace std;
class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m, vector<int>(n));
        dp.at(0).at(0) = 1;
        for (int i = 1; i < n; ++i)
        {
            dp.at(0).at(i) = 1;
        }
        for (int j = 1; j < m; ++j)
        {
            dp.at(j).at(0) = 1;
        }
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                dp.at(i).at(j) = dp.at(i - 1).at(j) + dp.at(i).at(j - 1);
            }
        }
        return dp.at(m - 1).at(n - 1);
    }
};