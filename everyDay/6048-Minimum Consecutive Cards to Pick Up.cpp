// 必须拿起的最小连续卡牌数
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution 
{
public:
    int minimumCardPickup(vector<int>& cards) 
    {
        // 记录以 cards[i] 这张卡牌有多少间距
        unordered_set<int> se;
        unordered_map<int, int> ma;
        int size = cards.size();
        int minNum = INT_MAX;
        for (int i = 0; i < size; ++i)
        {
            long curNum = cards.at(i);
            if (se.count(curNum) == 0)
            {
                se.insert(curNum);
                ma.insert(pair<int,int>(curNum, i));
            }
            else    // 这张卡牌在之前已经拿过
            {
                int length = i - ma[curNum] + 1;
                if (length <= minNum)
                {
                    minNum = length;
                    ma[curNum] = i; // 更新最近的下标
                }
            }
        }
        if (minNum == INT_MAX)
        {
            minNum = -1;
        }
        return minNum;
    }
};
int main()
{
    Solution s;
    vector<int> v{3, 4, 3, 4, 4, 4};
    s.minimumCardPickup(v);
}