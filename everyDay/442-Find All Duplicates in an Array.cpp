// 数组中重复的数据
#include <vector>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    vector<int> findDuplicates(vector<int>& nums) 
    {
        vector<int> result;
        int index = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            while (nums.at(i) != nums.at(nums.at(i) - 1))
            {
                swap(nums.at(i), nums.at(nums.at(i) - 1));
            }
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums.at(i) != i + 1)
            {
                result.push_back(nums.at(i));
            }
        }
        return result;
    }
};
int main()
{
    Solution s;
    vector<int> v{4, 3, 2, 7, 8, 2, 3, 1};
    s.findDuplicates(v);
}