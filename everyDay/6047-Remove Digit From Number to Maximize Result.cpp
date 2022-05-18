// 移除指定数字得到的最大结果
#include <vector>
#include <string>
using namespace std;
class Solution 
{
public:
    string removeDigit(string number, char digit) 
    {
        string result;
        string maxNum;
        int start = 0;
        ssize_t pos;
        while ((pos = number.find_first_of(digit, start)) != string::npos)
        {
            string num = number;
            num.erase(num.begin() + pos);
            if (num > maxNum)
            {
                result = num;
                maxNum = num;
            }
            start = pos + 1;
        }
        return result;
    }
};

int main()
{
    Solution s;
    string str = "551";
    s.removeDigit(str, '5');
}