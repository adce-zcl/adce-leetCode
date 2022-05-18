// 随机数索引
#include <vector>
#include <unordered_map>
#include <random>
using namespace std;
class Solution 
{
private:
    unordered_map<int, vector<int>> ma;

public:
    Solution(vector<int>& nums)
    {
        for (size_t i = 0; i < nums.size(); ++i)
        {
            ma[nums.at(i)].push_back(i);
        }
    }
    
    int pick(int target) 
    {
        if (ma[target].size() == 1)
        {
            return ma[target].front();
        }
        else
        {
            int index = rand() % ma[target].size();
            return ma[target].at(index);
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */