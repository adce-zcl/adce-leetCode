// K 次取反后最大化的数组和
// 贪心算法
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
bool cmp(int &a, int &b)
{
    return abs(a) > abs(b);
}
class Solution 
{
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) 
    {
        sort(nums.begin(), nums.end(), cmp);
        for (auto &&num : nums)
        {
            if (num < 0 && k > 0)
            {
                num = -num;
                --k;
            }
        }
        while (k > 0)
        {
            nums.at(nums.size() - 1) = -nums.at(nums.size() - 1);
            --k;
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};