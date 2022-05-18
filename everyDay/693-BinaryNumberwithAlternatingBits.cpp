// 交替位二进制数

class Solution 
{
public:
    bool hasAlternatingBits(int n) 
    {
        long n1 = n >> 1;
        long a = n1 ^ n;
        if((a & (a + 1)) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
  
    }
};