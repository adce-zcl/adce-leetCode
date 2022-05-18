// 字符的最短距离
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    vector<int> shortestToChar(string s, char c) 
    {
        int size = static_cast<int>(s.size());
        vector<int> result(size, -1);
        int pos = -1;
        for (int i = 0; i < size; ++i)
        {
            if (s.at(i) == c)
            {
                pos = i;
                result.at(i) = 0;
            }
            else if (pos != -1)
            {
                result.at(i) = i - pos;
            }
        }
        pos = -1;
        for (int i = size - 1; i > 0; --i)
        {
            if (s.at(i) == c)
            {
                pos = i;
            }
            else if (pos != -1)
            {
                if (result.at(i) == -1)
                {
                    result.at(i) = -(i - pos);
                }
                else
                {
                    result.at(i) = min(result.at(i), -(i - pos));
                }
            }
        }
        return result;
    }
};
int main()
{
    Solution s;
    string str = "loveleetcode";
    char c = 'e';
    s.shortestToChar(str, c);
}