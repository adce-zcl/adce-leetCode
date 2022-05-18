// 多个数组求交集
#include <vector>
#include <unordered_map>
using namespace std;
class Solution 
{
public:
    vector<int> intersection(vector<vector<int>>& nums) 
    {
        unordered_map<int, int> ma;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            for (size_t j = 0; j < nums.at(i).size(); ++j)
            {
                ma[nums.at(i).at(j)]++;
            }
        }
        vector<int> result;
        for (auto &&i : ma)
        {
            if (i.second == nums.size())
            {
                result.push_back(i.first);
            }
        }
        return result;
    }
};