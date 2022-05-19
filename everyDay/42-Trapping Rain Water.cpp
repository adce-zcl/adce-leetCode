// 接雨水
#include <vector>
using namespace std;
class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int size = height.size();
        if (size < 2)
        {
            return 0;
        }
        vector<int> maxLeft(size, 0);
        vector<int> maxRight(size, 0);
        maxLeft.at(0) = height.at(0);
        maxRight.at(size - 1) = height.at(size - 1);
        for (int i = 1; i < size; ++i)
        {
            maxLeft.at(i) = max(height.at(i), maxLeft.at(i - 1));
        }
        for (int j = size - 2; j >= 0; --j)
        {
            maxRight.at(j) = max(height.at(j), maxRight.at(j + 1));
        }
        int ans = 0;
        for (int i = 1; i < size - 1; ++i)
        {
            int n = min(maxLeft.at(i), maxRight.at(i)) - height.at(i);
            if (n > 0)
            {
                ans += n;
            }
        }
        return ans;
    }
};