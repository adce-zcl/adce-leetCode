// 全排列 II
// 任意顺序？直接排序！
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution 
{
private:
    vector<int> path;
    vector<vector<int>> result;
    unordered_set<int> se;
    void backTracking(vector<int> &nums)
    {
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (se.count(i) != 0 || ( i != 0 && se.count(i - 1) != 0 && nums.at(i) == nums.at(i - 1)))
            {
                continue;
            }
            se.insert(i);
            path.push_back(nums.at(i));
            backTracking(nums);
            path.pop_back();
            se.erase(i);
        }
        return;
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        backTracking(nums);
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1, 1, 2};
    s.permuteUnique(nums);
}