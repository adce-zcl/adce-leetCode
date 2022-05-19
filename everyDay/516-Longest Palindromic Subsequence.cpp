// 最长回文子序列
#include <string>
#include <vector>
using namespace std;
class Solution 
{
public:
    int longestPalindromeSubseq(string s) 
    {
        int size = s.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));
        for (int i = 0; i < size; ++i)
        {
            dp.at(i).at(i) = 1;
        }
        
        for (int i = size - 1; i >= 0; --i)
        {
            for (int j = i + 2; j < size; ++j)
            {
                if (s.at(i) == s.at(j))
                {
                    dp.at(i).at(j) = dp.at(i + 1).at(j - 1) + 2;
                }   
                else
                {
                    int n1 = dp.at(i + 1).at(j);
                    int n2 = dp.at(i).at(j - 1);
                    dp.at(i).at(j) = max(n1, n2);
                }    
            }
        }
        return dp.at(0).at(size - 1);
    }
};