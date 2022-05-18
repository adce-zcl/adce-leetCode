// 组合
#include <vector>
using namespace std;

class Solution 
{
private:
    vector<vector<int>> result;
    vector<int> path;
    void backTracking(int n, int k, int start_index)
    {
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }
        for (int i = start_index; i <= n - (k - path.size()) + 1; ++i)
        {
            path.push_back(i);
            backTracking(n, k, i + 1);
            path.pop_back();
        }
        return;
    }
public:
    // 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
    vector<vector<int>> combine(int n, int k) 
    {
        backTracking(n, k, 0);
        return result;
    }
};