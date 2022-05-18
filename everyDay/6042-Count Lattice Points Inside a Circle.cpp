// 统计圆内格点数目
#include <vector>
#include <unordered_set>
using namespace std;

//自定义哈希函数，元素类型为 pair<T1, T2> a(X1, X2);
struct pair_hash
{
    template <class T1, class T2>
    size_t operator () (pair<T1, T2> const &pair) const
    {
        size_t h1 = hash<T1>()(pair.first); //用默认的 hash 处理 pair 中的第一个数据 X1
        size_t h2 = hash<T2>()(pair.second);//用默认的 hash 处理 pair 中的第二个数据 X2
        return h1 ^ h2;
    }
};

class Solution 
{
public:
    int countLatticePoints(vector<vector<int>>& circles) 
    {
        int count = 0;
        unordered_set<pair<int, int>, pair_hash> se;
        for (auto &&circle : circles)
        {
            int x = circle.at(0);
            int y = circle.at(1);
            int r = circle.at(2);
            // 每次记录面积最大的那个圆？
            for (int xi = x - r; xi <= x + r; ++xi)
            {
                for (int yi = y - r; yi <= y + r; ++yi)
                {
                    pair<int, int> point(xi, yi);
                    if (se.count(point) == 0)
                    {
                        int length = (xi - x) * (xi - x) + (yi - y) * (yi - y);
                        if (length <= r * r)
                        {
                            ++count;
                            se.insert(point);
                        }
                    }
                }
            }
        }
        return count;
    }
};