// 电话号码的字母组合
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution 
{
private:
    string path;
    vector<string> result;
    void backTracking(unordered_map<char,string> uma, string digits, int index)
    {
        if (path.size() == digits.size())
        {
            result.push_back(path);
            return;
        }
        char cur_ch = digits.at(index);
        string cur_str = uma.at(cur_ch);
        for (size_t i = 0; i < cur_str.size(); ++i)
        {
            path.push_back(cur_str.at(i));
            backTracking(uma, digits, index + 1);
            path.pop_back();
        }
        return;
    }
public:
    vector<string> letterCombinations(string digits) 
    {
        if (digits.empty())
        {
            return result;
        }
        unordered_map<char, string> uma{\
        {'2', "abc"}, {'3', "def"}, \
        {'4', "ghi"}, {'5', "jkl"}, \
        {'6', "mno"}, {'7', "pqrs"}, \
        {'8', "tuv"}, {'9', "wxyz"}};
        backTracking(uma, digits, 0);
        return result;
    }
};