// 唯一摩尔斯密码词
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution 
{
public:
    int uniqueMorseRepresentations(vector<string>& words) 
    {
        unordered_set<string> se;
        vector<string> dictionary{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        for (auto &&word : words)
        {
            string cur_dic = "";
            for (auto &&ch : word)
            {
                cur_dic += dictionary.at(ch - 'a');
            }
            if (se.count(cur_dic) == 0)
            {
                se.insert(cur_dic);
            }
        }
        return se.size();
    }
};