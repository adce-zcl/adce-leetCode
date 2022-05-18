#include <vector>
using namespace std;
// 双指针法(快慢指针)
class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int fast_index = 0, slow_index = 0;
        for (fast_index; fast_index < nums.size(); ++fast_index)
        {
            if(nums.at(fast_index) != val)
            {
                swap(nums.at(fast_index), nums.at(slow_index));
                ++slow_index;
            }
        }
        return slow_index;
    }
};