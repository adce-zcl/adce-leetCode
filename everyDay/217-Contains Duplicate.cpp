// 存在重复元素
#include <vector>
#include <unordered_set>
using namespace std;
class Solution 
{
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_set<int> se;
        for (auto &&num : nums)
        {
            if (se.count(num) == 1)
            {
                return true;
            }
            else
            {
                se.insert(num);
            }
        }
        return false;
    }
};