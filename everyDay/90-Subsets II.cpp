// 子集 II
// 去重
#include <vector>
#include <algorithm>
using namespace std;
class Solution 
{
private:
    vector<int> path;
    vector<vector<int>> result;
    void backTracking(vector<int> &nums, int start_index)
    {
        for (size_t i = start_index; i < nums.size(); ++i)
        {
            if (i != start_index && nums.at(i) == nums.at(i - 1))
            {
                continue;
            }
            path.push_back(nums.at(i));
            result.push_back(path);
            backTracking(nums, i + 1);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        result.push_back(path);
        // 排序很有必要，不然去重不好，因为函数里只判断了相邻的两个
        sort(nums.begin(), nums.end()); 
        backTracking(nums, 0);
        return result;
    }
};