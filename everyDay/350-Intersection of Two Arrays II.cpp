// 两个数组的交集 II
#include <vector>
#include <unordered_map>
using namespace std;
class Solution 
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> ma;
        for (auto &&num2 : nums2)
        {
            ++ma[num2];
        }
        vector<int> result;
        for (auto &&num1 : nums1)
        {
            if (ma.count(num1) > 0 && ma[num1] > 0)
            {
                result.push_back(num1);
                ma[num1]--;
            }
        }
        return result;
    }
};