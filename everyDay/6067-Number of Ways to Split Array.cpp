// 分割数组的方案数
#include <vector>
using namespace std;
class Solution 
{
public:
    int waysToSplitArray(vector<int>& nums) 
    {
        vector<long> sums;
        long sum = 0;
        for (auto &&num : nums)
        {
            sum += num;
            sums.push_back(sum);
        }
        int index = 0;
        int count = 0;
        while (index < nums.size() - 1)
        {
            if (sums.at(index) >= sum - sums.at(index))
            {
                ++count;
            }
            ++index;
        }
        return count;
    }
};