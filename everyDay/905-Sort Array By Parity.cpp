// 按奇偶排序数组
#include <vector>
using namespace std;
class Solution 
{
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        int start = 0;  // 偶数
        int end = nums.size() - 1;  // 奇数
        while (start < end)
        {
            if (nums.at(start) % 2 != 0 && nums.at(end) % 2 == 0)
            {
                swap(nums.at(start), nums.at(end));
                --end;
                ++start;
            }
            else if (nums.at(start) % 2 != 0)    // 是奇数
            {
                --end;
            }
            else if (nums.at(end) % 2 == 0)  // 偶数
            {
                ++start;
            }
        }
        return nums;
    }
};