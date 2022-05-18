// 不同的子序列
#include <string>
#include <vector>
using namespace std;
class Solution 
{
public:
    int numDistinct(string s, string t) 
    {
        // s是大串
        vector<vector<double>> dp(s.size() + 1, vector<double>(t.size() + 1));
        for (int i = 0; i < s.size() + 1; ++i)
        {
            dp.at(i).at(0) = 1;
        }
        for (int j = 0; j < t.size() + 1; ++j)
        {
            dp.at(0).at(j) = 0;
        }
        dp.at(0).at(0) = 1;
        for (int i = 1; i <= s.size(); ++i)
        {
            for (int j = 1; j <= t.size(); ++j)
            {
                if (s.at(i - 1) == t.at(j - 1))
                {
                    dp.at(i).at(j) = dp.at(i - 1).at(j - 1) + dp.at(i - 1).at(j);
                }
                else
                {
                    dp.at(i).at(j) = dp.at(i - 1).at(j);
                }
            }
        }
        return dp.at(s.size()).at(t.size());
    }
};