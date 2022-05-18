// 复原 IP 地址
#include <vector>
#include <string>
using namespace std;
class Solution 
{
private:
    vector<string> result;
    // 判断字符串s在左闭又闭区间[start, end]所组成的数字是否合法
    bool isValid(const string& s, int start, int end) 
    {
        if (start > end) 
        {
            return false;
        }
        if (s[start] == '0' && start != end) 
        { // 0开头的数字不合法
                return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) 
        {
            if (s[i] > '9' || s[i] < '0') 
            { // 遇到非数字字符不合法
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) 
            { // 如果大于255了不合法
                return false;
            }
        }
        return true;
    }

    // 虽然题目要求不更改s，但是因为我们是回溯，s只会在过程中改变，最后s仍然不变
    // 而push到vector是复制的操作，所以很省事
    void backTracking(string &s, int start_index, int pointNum)
    {
        // 每次截取[start_index - i]的长度
        if (pointNum == 3)  // 第三个点已经打上，看第四部分数据是否满足
        {
            if (isValid(s, start_index, s.size() - 1))
            {
                result.push_back(s);
            }
            return;
        }
        for (size_t i = start_index; i < s.size(); ++i)
        {
            if (!isValid(s, start_index, i))
            {
                break;  // 不合法直接退出
            }
            // [start_index,i]的字符合法，添加到字符串中
            s.insert(s.begin() + i + 1, '.');
            backTracking(s, i + 2, pointNum + 1);   // i + 1 的位置是'.'
            s.erase(s.begin() + i + 1);
        }
        return;
    }

public:
    vector<string> restoreIpAddresses(string s) 
    {
        if (s.size() > 12)
        {
            return result;
        }
        backTracking(s, 0, 0);
        return result;
    }
};