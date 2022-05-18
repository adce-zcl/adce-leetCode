// 跳跃游戏 II
#include <vector>
using namespace std;
class Solution 
{
public:
    int jump(vector<int>& nums) 
    {
        int count = 0;
        int curSpace = 0;
        int nextSpace = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            nextSpace = max(i + nums.at(i), nextSpace);
            if (i == curSpace)
            {
                ++count;
                curSpace = nextSpace;
            }
        }
        return count;
    }
};