// 各位相加
class Solution 
{
public:
    int addDigits(int num) 
    {
        if(num / 10 == 0)   // 一位数
        {
            return num;
        }
        int temp = 0;
        do
        {
            while (num != 0)
            {
                temp += num % 10;    // 个位
                num = num / 10;
            }
            num = temp;
            temp = 0;
        } while (num >= 10);
        return num;
    }
};