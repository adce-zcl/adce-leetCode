#include <vector>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        int current;
        while (left < right)
        {
            // 防止溢出
            mid = (right - left) / 2 + left;
            // mid = (right + left) / 2;
            current = nums.at(mid);
            if (current == target)
            {
                return mid;
            }
            else if (current < target)
            {
                left = mid + 1;
            }
            else if (current > target)
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> v = {-1, 0, 3, 5, 9, 12};
}