// 到达终点
// 辗转相除法的应用
#include <algorithm>
using namespace std;
class Solution 
{
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) 
    {
        while (tx > sx && ty > sy && tx != ty)
        {
            if (tx > ty)
            {
                tx = tx % ty;
            }
            else
            {
                ty = ty % tx;
            }
        }
        if (tx == sx && ty == sy)
        {
            return true;
        }
        else if (tx == sx)
        {
            return ty > sy && (ty - sy) % tx == 0;
        }
        else if (ty == sy)
        {
            return tx > sx && (tx - sx) % ty == 0;
        }
        return false;
    }
};