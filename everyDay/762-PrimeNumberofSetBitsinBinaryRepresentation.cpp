// 二进制表示中质数个计算置位
// int的类型为2^31，10^9，这之间的质数可以打表存储
// 但是这次用个帅的解法 - 质数的掩码

class Solution 
{
public:
    int countPrimeSetBits(int left, int right) 
    {
        int ans = 0;
        // mask=665772=10100010100010101100 来存储这些质数
        unsigned int mask = 665772;
        for (int i = left; i <= right; ++i)
        {
            // __builtin_popcount(i) 统计i中二进制1的个数
            if (1 << __builtin_popcount(i) & mask)
            {
                ++ans;
            }
        }
        return ans;
    }
};
int main()
{
    Solution s;
    s.countPrimeSetBits(1,100);
}