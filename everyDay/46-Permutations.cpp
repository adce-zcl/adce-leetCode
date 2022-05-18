// 全排列
#include <vector>
#include <unordered_set>
using namespace std;
class Solution 
{
private:
    vector<int> path;
    vector<vector<int>> result;
    unordered_set<int> se;
    void backTracking(vector<int> &nums, unordered_set<int> &se)
    {
        if (path.size() == nums.size())
        {
            result.push_back(path);
            return;
        }
        for (size_t i = 0; i < nums.size(); ++i)
        {
            if (se.count(nums.at(i)) != 0)
            {
                continue;
            }
            path.push_back(nums.at(i));
            se.insert(nums.at(i));
            backTracking(nums, se);
            se.erase(nums.at(i));
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        backTracking(nums, se);
        return result;
    }
};