// 分发糖果
#include <vector>
#include <numeric>
using namespace std;
class Solution 
{
public:
    int candy(vector<int>& ratings) 
    {
        vector<int> candys(ratings.size(), 1);
        // 从左往右遍历，看每一个孩子的右侧孩子
        for (int i = 1; i < ratings.size(); ++i)
        {
            if (ratings.at(i) > ratings.at(i - 1))
            {
                candys.at(i) = candys.at(i - 1) + 1;
            }
        }

        // 从右往左遍历，看每一个孩子的左侧相邻孩子
        for (int i = ratings.size() - 2; i >= 0; --i)
        {
            if (ratings.at(i) > ratings.at(i + 1))
            {
                candys.at(i) = candys.at(i) > candys.at(i + 1) ? candys.at(i) : candys.at(i + 1) + 1;
            }
        }
        return accumulate(candys.begin(), candys.end(),0);
    }
};