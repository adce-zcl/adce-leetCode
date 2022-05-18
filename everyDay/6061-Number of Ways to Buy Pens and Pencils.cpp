// 买钢笔和铅笔的方案数
class Solution 
{
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) 
    {
        long long result = 0;
        for (long long i = 0; i*cost1 <= total; ++i)
        {
            int cur = total - i * cost1;
            result += cur / cost2 + 1;
        }
        return result;
    }
};