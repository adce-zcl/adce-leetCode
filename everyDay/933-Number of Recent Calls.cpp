// 最近的请求次数
#include <vector>
using namespace std;
class RecentCounter 
{
private:
    vector<long> clients;
    int size;
    int startTime;
    int endTime;
    int maxQeu;

public:
    RecentCounter() 
    {
        startTime = 0;
        endTime = 0;
        maxQeu = 0;
        size = 0;
    }
    
    int ping(int t) 
    {
        clients.push_back(t);
        ++size;
        endTime = size - 1;
        ++maxQeu;
        while (clients.at(endTime) - clients.at(startTime) > 3000) // startTime前移
        {
            ++startTime;
            --maxQeu;
        }
        return maxQeu; 
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */