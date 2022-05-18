// 贴纸拼词
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution 
{
public:
    int minStickers(vector<string>& stickers, string target) 
    {
        vector<int> dp(target.size() + 1, INT_MAX);
        unordered_map<char, int> ma;

        

        return dp.at(target.size());
    }
};