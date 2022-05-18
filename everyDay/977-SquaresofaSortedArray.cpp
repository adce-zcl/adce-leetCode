// 有序数组的平法
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int size = nums.size();
        vector<int> value(size);
        int left = 0;
        int right = nums.size() - 1;
        int pow_left, pow_right;
        int value_index = right;
        while (left <= right)
        {
            pow_left = nums.at(left) * nums.at(left);
            pow_right = nums.at(right) * nums.at(right);
            if(pow_left < pow_right)
            {
                value.at(value_index--) = nums.at(right) * nums.at(right);
                --right;
            }
            else
            {
                value.at(value_index--) = nums.at(left) * nums.at(left);
                ++left;
            }
        }
        return value;
    }
};

int main()
{
    Solution s;
    vector<int> v = {-4, -1, 0, 3, 10};
    s.sortedSquares(v);
}