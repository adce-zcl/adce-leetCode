// 替换字符串中的空格
#include <string>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    string replaceSpace(string s) 
    {
        auto space_pos = s.find_first_of(" ");
        while (space_pos != string::npos)
        {
            s.insert(space_pos, "%20");
            s.erase(space_pos + 3, 1);
            space_pos = s.find_first_of(" ");
        }
        return s;
    }
};