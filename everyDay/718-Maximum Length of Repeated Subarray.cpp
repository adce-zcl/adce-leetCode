// 最长重复子数组
#include <vector>
using namespace std;
class Solution 
{
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int result = 0;
        for (int i = 1; i <= nums1.size(); ++i)
        {
            for (int j = 1; j <= nums2.size(); ++j)
            {
                if (nums1.at(i-1) == nums2.at(j-1))
                {
                    dp.at(i).at(j) = dp.at(i - 1).at(j - 1) + 1;
                    if (dp.at(i).at(j) > result)
                    {
                        result = dp.at(i).at(j);
                    }
                }
            }
        }
        return result;
    }
};