// 字典序的第K小数字
// 给定整数 n 和 k，返回  [1, n] 中字典序第 k 小的数字。

// 利用字典树，只用值来模拟
#include <cmath>
class Solution 
{
public:
    int findKthNumber(int n, int k) 
    {
        int value = 1;
        --k;
        while(k>0)
        {
            int current = nums(value,n);
            if(current > k)
            {
                value=value*10;
                --k;
            }
            else
            {
                k=k-current;
                ++value;
            }
        }
        return value;
    }

    // 使用long，防止范围溢出
    int nums(int index,long n)
    {
        // 使用每层遍历的方式逐层计算每一层的个数
        // 刚开始就在index层
        int num = 0;  // 最开始个数是0
        long first = index;
        long last = index;   // 刚开始first和last就在index这个节点上
        while(first <= n)
        {
            // 当前层的节点个数
            num += std::min(last,n) - first + 1;
            // 进入下一层
            first = first * 10;
            last = last * 10 + 9;
        }
        return num;
    }
};
