// 最少移动次数使数组元素相等 II
// 中位数
#include <vector>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    int minMoves2(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int begin = 0, end = nums.size() - 1;
        while (begin < end)
        {
            ans += abs(nums.at(end) - nums.at(begin));
            ++begin;
            --end;
        }
        return ans;
    }
};