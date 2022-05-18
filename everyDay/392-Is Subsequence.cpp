// 判断子序列
// 动态规划
#include <string>
#include <vector>
using namespace std;
class Solution 
{
public:
    bool isSubsequence(string s, string t) 
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); ++i)
        {
            for (int j = 1; j <= t.size(); ++j)
            {
                if (s.at(i - 1) == t.at(j - 1))
                {
                    dp.at(i).at(j) = dp.at(i - 1).at(j - 1) + 1;
                }
                else
                {
                    dp.at(i).at(j) = dp.at(i).at(j - 1);
                }
            }
        }
        if (dp.at(s.size()).at(t.size()) == s.size())
        {
            return true;
        }
        return false;
    }
};