// 跳跃游戏
// 贪心算法
#include <vector>
using namespace std;
class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        // 只要不跳到0不就行了么？
        int cover = 0;
        for (int i = 0; i <= cover; ++i)
        {
            cover = max(i + nums.at(i), cover);
            if (cover >= nums.size() - 1)
            {
                return true;
            }
        }
        return false;
    }
};