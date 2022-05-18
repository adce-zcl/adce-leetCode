// 子集
// 子集操简单？！
#include <vector>
using namespace std;
class Solution 
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(vector<int> &nums, int start_index)
    {
        for (size_t i = start_index; i < nums.size(); ++i)
        {
            path.push_back(nums.at(i));
            result.push_back(path);
            backTracking(nums, i + 1);
            path.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        result.push_back(vector<int>());
        backTracking(nums, 0);
        return result;
    }
};