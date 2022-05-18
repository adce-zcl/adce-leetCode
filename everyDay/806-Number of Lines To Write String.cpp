// 写字符串需要的行数
#include <vector>
#include <string>
using namespace std;
class Solution 
{
public:
    vector<int> numberOfLines(vector<int>& widths, string s) 
    {
        int cur_row = 0;
        vector<int> value(2);
        for (auto &&i : s)
        {
            int cur = cur_row + widths.at(i - 'a');
            if (cur < 100)
            {
                cur_row = cur;
            }
            else if (cur == 100)
            {
                ++value.at(0);
                cur_row = 0;
            }
            else
            {
                ++value.at(0);
                cur_row = widths.at(i - 'a');
            }
        }
        if (cur_row != 0)
        {
            ++value.at(0);
            value.at(1) = cur_row;
        }
        else
        {
            value.at(1) = 100;
        }
        return value;
    }
};

int main()
{
    vector<int> widths{4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    string str = "bbbcccdddaaa";
    Solution s;
    s.numberOfLines(widths, str);
}