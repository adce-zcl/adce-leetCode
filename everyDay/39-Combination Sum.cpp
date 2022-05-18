// 组合总和
#include <algorithm>
#include <vector>
using namespace std;
class Solution 
{
private:
    vector<int> path;
    vector<vector<int>> result;
    void backTracking(vector<int> &candidates, int &target, int sum, int start_index)
    {
        if (sum == target)
        {
            result.push_back(path);
            return;
        }
        if (sum > target)
        {
            return;
        }
        for (size_t i = start_index; i < candidates.size(); ++i)
        {
            path.push_back(candidates.at(i));
            sum += candidates.at(i);
            backTracking(candidates, target, sum, i);
            sum -= candidates.at(i);
            path.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        backTracking(candidates, target, 0, 0);
        return result;
    }
};