// 最长连续递增序列
#include <vector>
using namespace std;
class Solution 
{
public:
    int findLengthOfLCIS(vector<int>& nums) 
    {
        int maxlength = 1;
        int size = nums.size();
        int pre = nums.at(0);
        vector<int> dp(size, 1);
        for (int i = 1; i < size; ++i)
        {
            if (nums.at(i) > pre)
            {
                dp.at(i) = dp.at(i - 1) + 1;
                if (dp.at(i) > maxlength)
                {
                    maxlength = dp.at(i);
                }
            }
            else
            {
                dp.at(i) = 0;
            }
            pre = nums.at(i);
        }
        return maxlength;
    }
};