// 毯子覆盖的最多白色砖块数
#include <vector>
#include <algorithm>
using namespace std;
class Solution 
{
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        if (a.at(0) < b.at(0))
        {
            return true;
        }
        else if (a.at(0) == b.at(0) && a.at(1) < b.at(1))
        {
            return true;
        }
        return false;
    }
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) 
    {
        sort(tiles.begin(), tiles.end(), compare);
        // [left,right)
        int left = 1, right = left + carpetLen;
        int maxcount = 0;
        int size = tiles.size();
        while (right <= tiles.at(size - 1).at(1))
        {
            int count = 0;
            for (int i = left; i < right; ++i)
            {
                
            }
            
        }
        
    }
};

int main()
{
    Solution s;
    vector<vector<int>> tiles{{10, 11}, {20, 25}, {30, 32}, {1, 5}, {12, 18},{12,9}};
    s.maximumWhiteTiles(tiles, 10);
}