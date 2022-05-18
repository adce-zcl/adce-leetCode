// 最长公共子序列
#include <string>
#include <vector>
using namespace std;
class Solution 
{
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i <= text1.size(); ++i)
        {
            for (int j = 1; j <= text2.size(); ++j)
            {
                if (text1.at(i-1) == text2.at(j-1))
                {
                    dp.at(i).at(j) = dp.at(i - 1).at(j - 1) + 1;
                }
                else
                {
                    dp.at(i).at(j) = max(dp.at(i - 1).at(j), dp.at(i).at(j - 1));
                }
            }
            
        }
        return dp.at(text1.size()).at(text2.size());
    }
};