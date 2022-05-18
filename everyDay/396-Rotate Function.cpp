// 旋转函数
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
class Solution 
{
private:
    int F(vector<int> &nums)
    {
        int sum = 0;
        int i = 0;
        for (auto &&num : nums)
        {
            sum += i++ * num;
        }
        return sum;
    }
public:
    int maxRotateFunction(vector<int>& nums) 
    {
        
        int sum_nums = 0;
        for (auto &&num : nums)
        {
            sum_nums += num;
        }
        int n = (int)nums.size();
        int maxSum = F(nums);
        int preSum = maxSum;
        for (size_t i = 1; i < nums.size(); ++i)
        {
            int curSum = preSum + sum_nums - n * nums.at(n - i);
            maxSum = max(maxSum, curSum);
            preSum = curSum;
        }
        return maxSum;
    }
};