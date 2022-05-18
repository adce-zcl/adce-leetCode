// 重新排列日志文件
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
class Solution 
{
public:
    static bool compare(const string &a, const string &b)
    {
        size_t a_pos = a.find_first_of(" ");
        size_t b_pos = b.find_first_of(" ");
        string a_content(a.begin() + a_pos + 1, a.end());
        string b_content(b.begin() + b_pos + 1, b.end());
        if (isdigit(a_content.at(0)) && isdigit(b_content.at(0)))
        {
            return false;
        }

        if (!isdigit(a_content.at(0)) && !isdigit(b_content.at(0)))
        {
            if (a_content == b_content)
            {
                return a < b;
            }
            return a_content < b_content;
        }

        if (isdigit(a_content.at(0)))
        {
            return false;
        }
        return true;
    }

    vector<string> reorderLogFiles(vector<string>& logs) 
    {
        stable_sort(logs.begin(), logs.end(), compare);
        return logs;
    }
};
int main()
{
    Solution s;
    vector<string> v{"dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero"};
    s.reorderLogFiles(v);
}