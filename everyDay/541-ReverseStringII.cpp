// 反转字符串II
#include <string>
using namespace std;
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        for (size_t i = 0; i <= s.size(); i += 2 * k)
        {
            if (s.size() - i < k)
            {
                reverse(s, i, s.size() - 1);
                //break;
            }
            else if (s.size() - i < 2 * k && s.size() - i >= k)
            {
                reverse(s, i, i + k - 1);
                //break;
            }
            if (i >= 2 * k)
            {
                reverse(s, i - 2 * k, i - k - 1);
            }
        }
        return s;
    }
    void reverse(string &s, int left, int right)
    {
        while (left < right)
        {
            swap(s.at(left++), s.at(right--));
        }
    }
};