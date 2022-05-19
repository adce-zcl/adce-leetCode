// 编辑距离
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
                // 不需要操作
                if (word1.at(i - 1) == word2.at(j - 1))
                {
                    dp.at(i).at(j) = dp.at(i - 1).at(j - 1);
                }
                else
                {
                    // 删除word1，或增加word2
                    int n1 = dp.at(i - 1).at(j) + 1;
                    // 删除word2，或增加word1
                    int n2 = dp.at(i).at(j - 1) + 1;
                    // 替换一个字符
                    int n3 = dp.at(i - 1).at(j - 1) + 1;
                    dp.at(i).at(j) = min(min(n1, n2), n3);
                }
            }
        }
        return dp.at(size1).at(size2);
    }
};