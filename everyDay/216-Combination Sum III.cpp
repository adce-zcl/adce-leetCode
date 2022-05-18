// 组合总和 III
#include <vector>
using namespace std;
class Solution 
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(int k, int n, int sum, int start_index)
    {
        if (path.size() > k || sum > n)    // 剪枝
        {
            return;
        }
        if (path.size() == k && sum == n)
        {
            result.push_back(path);
            return;
        }
        for (int i = start_index; i <= 9 - (k - path.size()) + 1; ++i)  // 剪枝
        {
            path.push_back(i);
            sum += i;
            backTracking(k, n, sum, i + 1);
            path.pop_back();
            sum -= i;
        }
        return;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        backTracking(k, n, 0, 1);
        return result;
    }
};
