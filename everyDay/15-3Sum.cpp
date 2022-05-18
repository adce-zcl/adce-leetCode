// 三数之和
// 使用哈希表很容易超时，因为去重不好做，
// 建议用双指针法。
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> value;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // 找 nums[i] + nums[left] + nums[right] == 0
        for (int i = 0; i < n; ++i)
        {
            if(nums.at(i) > 0)
            {
                break;
            }
            // i往右滑动的时候要去重
            if (i > 0 && nums.at(i) == nums.at(i-1)) 
            {
                continue;
            }
            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                if(nums.at(i) + nums.at(left) + nums.at(right) > 0)
                {
                    // 数字大了，right往左滑
                    --right;
                    while (left < right && nums.at(right) == nums.at(right + 1))
                    {
                        --right;
                    }
                }
                else if ( nums.at(i) + nums.at(left) + nums.at(right) < 0 )
                {
                    // 数字小了，left右移动
                    ++left;
                    while (left < right && nums.at(left) == nums.at(left - 1))
                    {
                        ++left;
                    }
                }
                else
                {
                    // == 0
                    value.push_back(vector<int>{i, left, right});
                    // 去重
                    while (left < right && nums.at(right) == nums.at(right - 1))
                    {
                        --right;
                    }
                    while (left < right && nums.at(left) == nums.at(left + 1))
                    {
                        ++left;
                    }
                    --right;
                    ++left;
                }
            }
        }
        return value;
    }
};