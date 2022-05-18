// 根据身高重建队列
#include <vector>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    bool comp(const vector<int> &a, const vector<int> &b)
    {
        if (a.at(0) == b.at(0))
        {
            return a.at(1) < b.at(1);
        }
        return a.at(0) > b.at(0);
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        // 先按照身高排序，再按照人数插入
        sort(people.begin(), people.end(), comp);

        // 按照.at(1)插入
        vector<vector<int>> que;
        for (int i = 0; i < (int)people.size(); ++i)
        {
            int pos = people.at(i).at(1);
            que.insert(que.begin() + pos, people.at(i));
        }
        return que;
    }
};