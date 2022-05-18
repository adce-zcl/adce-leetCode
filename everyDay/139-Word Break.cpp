// 单词拆分
// 动态规划 - 完全背包
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution 
{
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> se(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp.at(0) = true;
        for (int j = 1; j <= s.size(); ++j)
        {
            for (int i = 0; i < j; ++i)
            {
                if(dp.at(i))
                {
                    string word = s.substr(i, j - i);   // 注意dp的i比s的i往前一位
                    if (se.count(word) != 0)
                    {
                        dp.at(j) = true;
                    }
                }
            }
        }
        return dp.at(s.size());
    }
};