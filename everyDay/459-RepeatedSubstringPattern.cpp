// KMP
// kmp?弟弟而已
#include <string>
#include <vector>
using namespace std;
class Solution 
{
public:
    bool repeatedSubstringPattern(string s) 
    {
        int len = s.size();
        vector<int> next(len);
        getNext(next, s);
        if (next.at(len - 1) != 0 && len % (len - next.at(len - 1)) == 0)
        {
            return true;
        }
        return false;
    }
    void getNext(vector<int> &next, string &s)
    {
        next.at(0) = 0;
        int i = 1;
        int j = 0;
        for (; i < s.size(); ++i)
        {
            while (j > 0 && s.at(j) != s.at(i))
            {
                j = next.at(j - 1);
            }
            if (s.at(i) == s.at(j))
            {
                ++j;
            }
            next.at(i) = j;
        }
    }
};
int main()
{
    string s = "aba";
    Solution so;
    so.repeatedSubstringPattern(s);
}