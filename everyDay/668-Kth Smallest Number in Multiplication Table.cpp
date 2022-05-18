// 乘法表中第k小的数
// 二分法
class Solution 
{
private:
    // 计算rows-cols之间小于等于mid的数的个数
    int my_count(int rows, int cols, int mid)
    {
        int count = 0;
        int row = rows, col = 1;
        // 从矩阵的左下角计算到右上角
        while (row >= 1 && col <= cols)
        {
            int n = row * col;
            if (n <= mid)
            {
                count += row;
                ++col;
            }
            else
            {
                --row;
            }
        }
        return count;
    }
public:
    int findKthNumber(int m, int n, int k) 
    {
        int left = 1, right = m * n;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            // 查看left——right之间比mid小的数字有多少个
            int cnt = my_count(m, n, mid);
            if (cnt < k)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return left;
    }
};