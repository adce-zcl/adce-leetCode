// 不含特殊楼层的最大连续楼层数
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) 
    {
        sort(special.begin(), special.end());
        int size = special.size();
        int maxcount = special.at(0) - bottom;
        for (int i = 1; i < size; ++i)
        {
            maxcount = max(maxcount, special.at(i) - special.at(i - 1) - 1);
        }
        maxcount = max(maxcount, top - special.at(size - 1));
        return maxcount;
    }
};