// 2044. 统计按位或能得到最大值的子集数目
#include <iostream>
#include <vector>
using namespace std;
class ORMAX
{
public:
    // 按位运算，暴力求解
    int countMaxOrSubsets(vector<int> &nums);
};
int ORMAX::countMaxOrSubsets(vector<int>& nums)
{
    int maxnum = 0, maxValue = 0, n = nums.size(), bits = 1 << n;
    // 模拟位图
    for (int i = 0; i < bits; i++)
    {
        int current = 0;
        for (int j = 0; j < n; j++)
        {
            // 第j位为1，说明选择这一位数参与按位或计算
            if(((i>>j)&1) == 1)
            {
                current |= nums.at(j);
            }
        }
        if(current > maxValue)
        {
            maxValue = current;
            maxnum = 1;
        }
        else if(current == maxValue)    // 这里要用elseif，不然最开始0==0最多加1个
        {
            maxnum++;
        }
    }
    return maxnum;
}
