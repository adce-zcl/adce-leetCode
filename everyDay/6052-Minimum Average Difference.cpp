// 最小平均差
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution 
{
public:
    
    int minimumAverageDifference(vector<int>& nums) 
    {
        long sum = 0;
        vector<long> sums;
        for (auto &&num : nums)
        {
            sum += num;
            sums.push_back(sum);
        }
        int min_index = 0;
        long preSub = INT_MAX;
        long curSub;
        int size = nums.size();
        for (int i = 0; i < size; ++i)
        {
            long leftSum = sums.at(i);
            long left = leftSum / (i + 1);
            long right;
            if (i + 1 == size)
            {
                right = 0;
            }
            else
            {
                right = (sum - leftSum) / (size - (i + 1));
            }
            curSub = abs(left - right);
            if (curSub < preSub)
            {
                min_index = i;
                preSub = curSub;
            }
        }
        return min_index;
    }
};
int main()
{
    Solution s;
    vector<long> nums{2, 5, 3, 9, 5, 3};
    s.minimumAverageDifference(nums);
}