// 无重叠区间
// 贪心准则
#include <vector>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a.at(1) < b.at(1);
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        if (intervals.size() == 0)
        {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), compare);
        // 不重合的区间
        int count = 1;
        int end = intervals.at(0).at(1);
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals.at(i).at(0) >= end)
            {
                ++count;
                end = intervals.at(i).at(1);
            }
        }
        // 所有区间 - 不重合的区间 = 需要去除的区间
        return intervals.size() - count;
    }
};