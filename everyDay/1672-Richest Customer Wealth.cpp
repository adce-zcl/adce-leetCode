// 最富有客户的资产总量
#include <vector>
using namespace std;
class Solution 
{
public:
    int maximumWealth(vector<vector<int>>& accounts) 
    {
        int max = 0;
        for (size_t i = 0; i < accounts.size(); ++i)
        {
            int cur_max = 0;
            for (size_t j = 0; j < accounts.at(i).size(); ++j)
            {
                cur_max += accounts.at(i).at(j);
            }
            max = max > cur_max ? max : cur_max;
        }
        return max;
    }
};