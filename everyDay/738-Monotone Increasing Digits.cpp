// 单调递增的数字
#include <string>
using namespace std;
class Solution 
{
public:
    int monotoneIncreasingDigits(int n) 
    {
        string num(to_string(n));
        int flag;
        for (int i = num.size() - 1; i > 0; --i)
        {
            if (num.at(i - 1) > num.at(i))
            {
                num.at(i - 1) -= 1;
                flag = i;
            }
        }
        for (int i = flag; i < num.size(); ++i)
        {
            num.at(i) = '9';
        }
        return stoi(num);
    }
};