// 阶乘后的零
// 主要就是看有多少个10 的因子，而10由5和2构成
// 所以看有多少个5和2，并取两者的最小值
// 但是5的个数不可能大于2的个数，所以直接看1-n中有多少个因子5
class Solution {
public:
    int trailingZeroes(int n) 
    {
        int ans = 0;
        while (n) 
        {
            n /= 5;
            ans += n;
        }
        return ans;
    }
};