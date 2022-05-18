// 合并区间
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), compare);
        int left = intervals.at(0).at(0);
        int right = intervals.at(0).at(1);
        for (int i = 1; i < intervals.size(); ++i)
        {
            if (intervals.at(i).at(0) <= right)
            {
                right = max(right, intervals.at(i).at(1));
            }
            else
            {
                result.push_back({left, right});
                left = intervals.at(i).at(0);
                right = intervals.at(i).at(1);
            }
        }
        result.push_back({left, right});
        return result;
    }
};