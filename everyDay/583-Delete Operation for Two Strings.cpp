// 两个字符串的删除操作
#include <string>
#include <vector>
using namespace std;
class Solution 
{
public:
    int minDistance(string word1, string word2) 
    {
        int size1 = word1.size();
        int size2 = word2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, INT_MAX));
        for (int i = 0; i <= size1; ++i)
        {
            dp.at(i).at(0) = i;
        }
        for (int j = 0; j <= size2; ++j)
        {
            dp.at(0).at(j) = j;
        }
        for (int i = 1; i <= size1; ++i)
        {
            for (int j = 1; j <= size2; ++j)
            {
                if (word1.at(i - 1) == word2.at(j - 1))
                {
                    dp.at(i).at(j) = dp.at(i - 1).at(j - 1);
                }
                else
                {
                    dp.at(i).at(j) = min(dp.at(i - 1).at(j - 1) + 2, min(dp.at(i - 1).at(j) + 1, dp.at(i).at(j - 1) + 1));
                }
            }
        }
        return dp.at(size1).at(size2);
    }
};