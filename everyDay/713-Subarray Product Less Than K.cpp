// 乘积小于 K 的子数组
#include <vector>
using namespace std;
class Solution 
{
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        int size = nums.size();
        int ans = 0;
        int curProduct = 1;
        int start = 0, end = 0;
        for ( start, end; end < size; ++start, ++end)
        {
            curProduct *= nums.at(end);
            while (start <= end && curProduct >= k)
            {
                curProduct /= nums.at(start);
                ++start;
            }
            ans += end - start + 1;
        }
        return ans;
    }
};

int main()
{
    vector<int> v{10, 5, 2, 6};
    int k = 100;
    Solution s;
    s.numSubarrayProductLessThanK(v, k);
}