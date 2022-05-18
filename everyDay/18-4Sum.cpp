// 四数之和
// 双指针解法
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> value;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // nums[i] + nums[j] + nums[left] + nums[right] = target;
        for (int i = 0; i < n; ++i)
        {
            if (i > 0 && nums.at(i) == nums.at(i - 1))
            {
                continue; // 去重
            }
            for (int j = i + 1; j < n; ++j)
            {
                if (j > i + 1 && nums.at(j) == nums.at(j - 1))
                {
                    continue; // 去重
                }
                int left = j + 1;
                int right = n - 1;
                while (left < right)
                {
                    // 防止溢出
                    if (nums.at(i) + nums.at(j)  > target - (nums.at(left) + nums.at(right)))
                    {
                        //  和大了，right左移
                        --right;
                        while (left < right && nums.at(right) == nums.at(right + 1))
                        {
                            --right;    // 去重
                        }
                    }
                    else if (nums.at(i) + nums.at(j) < target - (nums.at(left) + nums.at(right)))
                    {
                        // 和小了，left右移
                        ++left;
                        while (left < right && nums.at(left) == nums.at(left - 1))
                        {
                            ++left;
                        }
                    }
                    else
                    {
                        value.push_back(vector<int>{nums.at(i), nums.at(j), nums.at(left), nums.at(right)});
                        while (left < right && nums.at(left) == nums.at(left + 1))
                        {
                            ++left;
                        }
                        while (left < right && nums.at(right) == nums.at(right - 1))
                        {
                            --right;
                        }
                        ++left;
                        --right;
                    }
                }
            }
        }
        return value;
    }
};