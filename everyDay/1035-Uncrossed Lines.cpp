// 不相交的线
// 动态规划 和 1143一样
#include <vector>
using namespace std;
class Solution 
{
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) 
    {
        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));
        for (int i = 1; i <= size1; ++i)
        {
            for (int j = 1; j <= size2; ++j)
            {
                if (nums1.at(i - 1) == nums2.at(j - 1))
                {
                    dp.at(i).at(j) = dp.at(i - 1).at(j - 1) + 1;
                }
                else
                {
                    dp.at(i).at(j) = max(dp.at(i - 1).at(j), dp.at(i).at(j - 1));
                }
            }
        }
        return dp.at(size1).at(size2);
    }
};