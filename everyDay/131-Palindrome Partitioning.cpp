// 分割回文串
#include <string>
#include <vector>
using namespace std;
class Solution 
{
private:
    bool isPalin(string &str, int start, int end)
    {
        while (start <= end)
        {
            if (str[start] != str[end])
            {
                break;
            }
            ++start;
            --end;
        }
        if (start <= end)
        {
            return false;
        }
        return true;
    }
    vector<string> path;
    vector<vector<string>> result;
    // s, 0 , 0
    // start = 从第几个开始分割
    // num 前面已经分割了几个
    void backTracking(string &s, int start)
    {
        if (start >= s.size())
        {
            result.push_back(path);
            return;
        }
        // 从1个开始分割，分割2个，分割3个...
        for (int i = start; i < s.size(); ++i)
        {
            bool isP = isPalin(s, start, i);    // A ,A和B的范围应该是一致的
            if (isP)
            {
                path.push_back(string(s.begin() + start, s.begin() + i + 1));   // B
            }
            else
            {
                continue;
            }
            backTracking(s, i + 1);
            path.pop_back();
        }
        return;
    }

public:
    vector<vector<string>> partition(string s) 
    {
        backTracking(s, 0);
        return result;
    }
};