// 计算字符串的数字和
#include <string>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    string digitSum(string s, int k) 
    {
        while (s.size() > k)
        {
            bool flag = true;
            int start = 0;
            int end = k;
            string str = "";
            while (true)
            {
                int cur_sum = 0;
                for (int i = start; i < end; ++i)
                {
                    cur_sum += (s.at(i) - '0');
                }
                str += to_string(cur_sum);
                if (end == s.size())
                {
                    break;
                }
                
                start = end;
                end = start + k > s.size() ? s.size() : start + k;
            }
            s = str;
        }
        return s;
    }
};

int main()
{
    Solution s;
    string str = "11111222223";
    int k = 3;
    s.digitSum(str, 3);
}