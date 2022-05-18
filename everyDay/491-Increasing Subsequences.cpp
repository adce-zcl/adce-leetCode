// 递增子序列
#include <vector>
#include <unordered_set>
using namespace std;
class Solution 
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(vector<int> &nums, int start_index)
    {
        if (path.size() >= 2)
        {
            result.push_back(path);
        }
        unordered_set<int> se;
        for (size_t i = start_index; i < nums.size(); ++i)
        {
            if (se.count(nums.at(i)) != 0)
            {
                continue;
            }
            if (!path.empty() && nums.at(i) < path.back())
            {
                continue;
            }
            se.insert(nums.at(i));
            path.push_back(nums.at(i));
            backTracking(nums, i + 1);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        backTracking(nums, 0);
        return result;
    }
};