// 找出游戏的获胜者
#include <queue>
using namespace std;
class Solution 
{
public:
    // [1,n]
    int findTheWinner(int n, int k) 
    {
        queue<int> que;
        for (int i = 1; i <= n; ++i)
        {
            que.emplace(i);
        }
    
        while (que.size() > 1)
        {
            for (int i = 1; i < k; ++i)
            {
                que.emplace(que.front());
                que.pop();
            }
            que.pop();
        }
        return que.front();
    }
};