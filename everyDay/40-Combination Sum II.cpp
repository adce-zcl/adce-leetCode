// 组合总和 II
#include <vector>
#include <algorithm>
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
        // int size = candidates.size() - start_index;
        for (size_t i = start_index; i < candidates.size(); ++i)
        {
            if (i != start_index && candidates.at(i) == candidates.at(i - 1))
            {
                continue;
            }  
            sum += candidates.at(i);
            if (sum > target)
            {
                sum -= candidates.at(i);
                continue;
            }
            path.push_back(candidates.at(i));
            backTracking(candidates, target, sum, i + 1);
            sum -= candidates.at(i);
            path.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        backTracking(candidates, target, 0, 0);
        return result;
    }
};