// 重新安排行程
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
class Solution 
{
private:
    vector<string> result;
    // string1 到 string2 的航班次数为 int
    // 且string2之内有序
    unordered_map<string, map<string, int>> targets;
    bool backTracking(int tickets_num, string pre)
    {
        if ((int)result.size() == tickets_num + 1)
        {
            return true;
        }
        if (targets.count(pre) == 0)
        {
            return false;
        }
        for (auto &&target : targets.at(pre))
        {
            if (target.second == 0) // 已经飞过了
            {
                continue;
            }
            result.push_back(target.first);
            --target.second;  // 次数已经用完
            // 这里必须有returen，否则会把结果全部弹走
            if (backTracking(tickets_num, target.first) == true)
            {
                return true;
            }
            ++target.second;
            result.pop_back();
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        for (auto &&target : tickets)
        {
            // 这里不能用at运算符，因为第一次元素不存在
            // 不能直接等于1，因为可能有好几张票
            ++targets[target.at(0)][target.at(1)];
        }
        result.push_back(string("JFK"));
        backTracking(tickets.size(), "JFK");
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> tickets =
        {{"EZE", "AXA"}, {"TIA", "ANU"}, {"ANU", "JFK"}, {"JFK", "ANU"}, {"ANU", "EZE"}, {"TIA", "ANU"}, {"AXA", "TIA"}, {"TIA", "JFK"}, {"ANU", "TIA"}, {"JFK", "TIA"}};
    s.findItinerary(tickets);
}