// 一和零
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (auto &&str : strs)
        {
            int count0 = 0, count1 = 0;
            for (auto &&ch : str)
            {
                if (ch == '0')
                {
                    ++count0;
                }
                else
                {
                    ++count1;
                }
            }
            
            for (int i = m; i >= 0; --i)
            {
                if (i < count0)
                {
                    break;
                }
                for (int j = n; j >= 0; --j)
                {
                    if (j < count1)
                    {
                        break;
                    }
                    dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i - count0).at(j - count1) + 1);
                }
            }
        }
        return dp.at(m).at(n);
    }
};