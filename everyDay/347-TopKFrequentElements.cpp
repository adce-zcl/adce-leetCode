// 前K个高频元素
// 优先级队列，却使用小顶堆
// 最后留在小顶堆中的就是前k大的元素
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution 
{

public:
    class MyCompare
    {
        public:
        bool operator()(const pair<int,int> &a, const pair<int,int> &b)
        {
            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> my_map;
        for (auto &&i : nums)
        {
            ++my_map[i];
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompare> my_queue;
        for (auto it = my_map.begin(); it != my_map.end(); ++it)
        {
            my_queue.push(*it);
            if ((int)my_queue.size() > k)
            {
                my_queue.pop();
            }
        }
        // 结果
        vector<int> value;
        while (!my_queue.empty())
        {
            value.push_back(my_queue.top().first);
            my_queue.pop();
        }
        return value;
    }
};
int main()
{
    Solution s;
    vector<int> nums{1,1,1,2,2,3};
    int k = 2;
    s.topKFrequent(nums, k);
}