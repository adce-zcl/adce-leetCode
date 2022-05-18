// 标签验证器
#include <string>
#include <regex>
using namespace std;
class Solution 
{
public:
    bool isValid(string code) 
    {
        regex r1 = regex("<!\\[CDATA\\[.*?\\]\\]>|t");
        regex r2 = regex("<([A-Z]{1,9})>[^<]*</\\1>");
        code = regex_replace(code, r1 , "-");
        string prev = "";
        while(code != prev)
        {
            prev = code;
            code = regex_replace(code, r2, "t");
        }
        return code == "t";
    }
};