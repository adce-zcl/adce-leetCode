// 山羊拉丁文
#include <string>
#include <unordered_set>
using namespace std;
class Solution 
{
public:
    string toGoatLatin(string sentence) 
    {
        unordered_set<char> se{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int index = 1;
        string result;
        string word;
        for (size_t i = 0; i <= sentence.size(); ++i)
        {
            if (i == sentence.size() || sentence.at(i) == ' ')  // 单词结束
            {
                if (se.count(word.at(0)) == 1)  // 如果这个单词的第一个字母是元音
                {
                    word += "ma";
                }
                else
                {
                    char ch = word.front();
                    word.erase(word.begin());
                    word.push_back(ch);
                    word += "ma";
                }
                for (int j = 0; j < index; ++j)
                {
                    word.push_back('a');
                }
                ++index;
                result += word;
                result.push_back(' ');
                word.clear();
                continue;
            }
            else
            {
                word.push_back(sentence.at(i));
            }
        }
        result.pop_back();
        return result;
    }
};
int main()
{
    Solution s;
    string str = "I speak Goat Latin";
    s.toGoatLatin(str);
}