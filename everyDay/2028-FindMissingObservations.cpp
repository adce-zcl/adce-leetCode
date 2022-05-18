// 找出缺失的观测数据
#include <vector>
#include <numeric>
using namespace std;
class Solution 
{
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) 
    {
        int total = mean * (n + rolls.size());
        int total_rolls = accumulate(rolls.begin(), rolls.end(), 0);
        int total_miss = total - total_rolls;
        int miss_i = total_miss / n;
        int miss_f = total_miss % n;
        if(miss_i <= 0)
        {
            return vector<int>();
        }
        else if(miss_i > 6)
        {
            return vector<int>();
        }
        else if(miss_i == 6 && miss_f != 0)
        {
            return vector<int>();
        }
        else if(miss_i == 6 && miss_f == 0)
        {
            return vector<int>(n, 6);
        }
        else
        {
            vector<int> value(n, miss_i);
            for (size_t i = 0; i < n; i++)
            {
                while (value[i] < 6)
                {
                    if(miss_f == 0)
                    {
                        return value;
                    }
                    value[i]++;
                    miss_f--;
                }
            }
        }
        return vector<int>();
    }
};