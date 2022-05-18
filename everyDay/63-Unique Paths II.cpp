// 不同路径 II
#include <vector>
#include <iostream>
using namespace std;
class Solution 
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid.at(0).size();
        vector<vector<int>> dp(m, vector<int>(n));
        if (obstacleGrid.at(0).at(0) == 1)
        {
            dp.at(0).at(0) = 0;
        }
        else
        {
            dp.at(0).at(0) = 1;
        }
        // cout << dp.at(0).at(0) << endl;
        for (int i = 1; i < n; ++i)
        {
            if (obstacleGrid.at(0).at(i) == 1)
            {
                dp.at(0).at(i) = 0;
            }
            else
            {
                if (dp.at(0).at(i - 1) == 0)
                {
                    dp.at(0).at(i) = 0;
                }
                else
                {
                    dp.at(0).at(i) = 1;
                }
            }
            // cout << dp.at(0).at(i) << endl;
        }

        for (int j = 1; j < m; ++j)
        {
            if (obstacleGrid.at(j).at(0) == 1)
            {
                dp.at(j).at(0) = 0;
            }
            else
            {
                if (dp.at(j - 1).at(0) == 0)
                {
                    dp.at(j).at(0) = 0;
                }
                else
                {
                    dp.at(j).at(0) = 1;
                }
            }
            // cout << dp.at(j).at(0) << endl;
        }
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (obstacleGrid.at(i).at(j) == 1)
                {
                    dp.at(i).at(j) = 0;
                }       
                else
                {
                    dp.at(i).at(j) = dp.at(i - 1).at(j) + dp.at(i).at(j - 1);
                }
                // cout << dp.at(i).at(j) << endl;
            }
        }
        return dp.at(m - 1).at(n - 1);
    }
};
int main()
{
    Solution s;
    vector<vector<int>> ob{{0}, {1}};
    s.uniquePathsWithObstacles(ob);
    system("pause");
}