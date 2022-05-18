// 两数之和
#include <vector>
#include <unordered_map>
using namespace std;
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            int sub = target - nums.at(i);
            auto it = m.find(sub);
            if(it == m.end())
            {
                m.emplace(nums.at(i), i);
                continue;
            }
            else if ( it->second != i)
            {
                return vector<int>{i, it->second};
            }
        }
        return vector<int>();
    }
};