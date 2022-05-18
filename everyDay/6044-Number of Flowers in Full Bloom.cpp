// 花期内花的数目
#include <vector>
#include <unordered_map>
using namespace std;
class Solution 
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) 
    {
        unordered_map<int, int> ma;
        for (auto &&flower : flowers)
        {
            for (size_t i = flower.at(0); i <= flower.at(1); ++i)
            {
                ma[i]++;
            }
        }
        vector<int> result;
        for (auto &&person : persons)
        {
            if (ma.count(person) != 0)
            {
                result.push_back(ma[person]);
            }
            else
            {
                result.push_back(0);
            }
        }
        return result;
    }
};