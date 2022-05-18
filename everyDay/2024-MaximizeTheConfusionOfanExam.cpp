// 考试的最大困扰度
#include <string>
using namespace std;
// 滑动窗口
// 题目可以等效于：求一段字符串，其中包含的F或者T不超过k个。
// 分别对应T的最大连续值和F的最大连续值
class Solution
{
public:
    int maxConsecutiveAnswers(string _answerKey, int _k)
    {
        answerKey = _answerKey;
        k = _k;
        return max(maxCnt('F'), maxCnt('T'));
    }

private:
    int k;
    string answerKey;
    int maxCnt(char c)
    {
        int n = answerKey.size();
        int right = 0, left = 0;
        int count = 0, ans = 0;
        // 求连续段，c的个数不超过k个
        while (right < n)
        {
            if (answerKey.at(right) == c)
            {
                count++;
            }

            while (count > k)
            {
                if (answerKey.at(left++) == c)
                {
                    count--;
                }
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string str = "TFFT";
    s.maxConsecutiveAnswers(str, 1);
}