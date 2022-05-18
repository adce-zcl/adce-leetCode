// 加油站
// 贪心算法
#include <vector>
using namespace std;
class Solution 
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int totalSum = 0;
        int curSum = 0;
        int start = 0;
        
        for (size_t i = 0; i < gas.size(); ++i)
        {
            totalSum += gas.at(i) - cost.at(i);
            curSum += gas.at(i) - cost.at(i);
            if (curSum < 0)
            {
                curSum = 0;
                start = i + 1;
            }
        }

        if (totalSum < 0)
        {
            return -1;
        }
        return start;
    }
};