// 快乐数
#include <algorithm>
#include <cmath>
#include <unordered_set>
using namespace std;
class Solution 
{
public:
    bool isHappy(int n) 
    {
        unordered_set<int> is_show;
        long temp = 0;
        int t;
        do
        {
            while (n != 0)
            {
                t = n % 10;
                temp += t * t;
                n = n / 10;
            }
            if(temp == 1)
            {
                return true;
            }
            else if (is_show.count(temp) == 1)  // 这个数字已经见过
            {
                return false;
            }
            is_show.insert(temp);
            n = temp;
            temp = 0;
        } while (true);  
    }
};