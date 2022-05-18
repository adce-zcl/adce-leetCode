// 颠倒字符串中的单词
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution
{
private:
    void removeSpace(string &s)
    {
        // 去除多余的空格  - 双指针法
        // 1.开头的多有空格
        // 2.末尾的所有空格
        // 3.中间的连续的空格只留一个
        int slow_index = 0;
        int fast_index = 0;
        // 去掉前面的字符串
        while (s.at(fast_index) == ' ')
        {
            ++fast_index;
        }
        while (fast_index < s.size())
        {
            if (slow_index > 0 && s.at(slow_index - 1) == ' ' && s.at(fast_index) == ' ')
            {
                ++fast_index;
            }
            else
            {
                s.at(slow_index++) = s.at(fast_index++);
            }
        }

        if (s.at(slow_index - 1) == ' ')
        {
            --slow_index;
        }
        // 重置s大小
        s.resize(slow_index);
    }
    void reverseWord(string &s)
    {
        auto left = s.begin();
        auto right = s.begin();
        while (right != s.end())
        {
            ++right;
            if (*right == ' ')
            {
                // 交换left ~ right-1
                reverse(left, right);
                left = right + 1;
            }
        }
        reverse(left, right);
    }
public:
    string reverseWords(string s)
    {
        removeSpace(s);
        reverse(s.begin(), s.end());
        reverseWord(s);
        return s;
    }
};

int main()
{
    Solution s;
    cout << s.reverseWords("  you  love i  ");
    system("pause");
}