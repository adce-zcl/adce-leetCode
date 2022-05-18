// 两个数组的交集
#include <vector>
#include <unordered_set>
using namespace std;

class Solution 
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_set<int> nums1_set;
        for (size_t i = 0; i < nums1.size(); i++)
        {
            if(nums1_set.count(nums1.at(i)) == 0)
            {
                nums1_set.emplace(nums1.at(i));
            }
        }
        vector<int> value;
        for (size_t i = 0; i < nums2.size(); i++)
        {
            if(nums1_set.count(nums2.at(i)) != 0)
            {
                value.push_back(nums2.at(i));
                nums1_set.erase(nums2.at(i));
            }
        }
        return value;
    }
};