// 用最少数量的箭引爆气球
#include <vector>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    static bool compare(const vector<int> &a, const vector<int> &b)
    {
        return a.at(0) < b.at(0);
    }
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        if (points.size() == 0)
        {
            return 0;
        }
        sort(points.begin(), points.end(), compare);
        int result = 1; // 最少为1箭
        for (int i = 1; i < points.size(); ++i)
        {
            // 如果当前气球的左边界小于上一组（注意是上一组）气球的右边界
            if (points.at(i).at(0) < points.at(i - 1).at(1))
            {
                // 修改这个气球的右边界为这一组的右边界
                points.at(i).at(1) = points.at(i - 1).at(1);
            }
            else
            {
                ++result;
            }
        }
        return result;
    }
};