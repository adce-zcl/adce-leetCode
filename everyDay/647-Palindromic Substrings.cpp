// 回文子串
#include <string>
#include <vector>
using namespace std;
class Solution 
{
public:
    int countSubstrings(string s) 
    {
        int size = s.size();
        vector<vector<bool>> dp(size, vector<bool>(size, false));
        int ans = 0;
        for (int i = size - 1; i >= 0; --i)
        {
            for (int j = i; j < size; ++j)
            {
                if (s.at(i) == s.at(j))
                {
                    if (i == j)
                    {
                        dp.at(i).at(j) = true;
                    }
                    else if (j - i <= 1)
                    {
                        dp.at(i).at(j) = true;
                    }
                    else
                    {
                        dp.at(i).at(j) = dp.at(i + 1).at(j - 1) & true;
                    }
                }
                if (dp.at(i).at(j) == true)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};