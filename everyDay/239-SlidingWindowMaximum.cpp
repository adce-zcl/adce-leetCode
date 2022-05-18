// 滑动窗口最大值
// 单调队列
#include <vector>
#include <deque>
using namespace std;
class MyQueue
{
private:
    deque<int> deq;
public:
    int top()
    {
        return deq.front();
    }
    void push(int value)
    {
        while (!deq.empty() && deq.back() < value)
        {
            deq.pop_back();
        }
        deq.push_back(value);
    }
    int pop()
    {
        int value = deq.front();
        deq.pop_front();
        return value;
    }
};
class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> value;
        int left = 0;
        int right = 0;
        int count = 1;
        int current_max;
        MyQueue my_queue;
        while (right < nums.size())
        {
            my_queue.push(nums.at(right));
            if (count == k)
            {
                value.push_back(my_queue.top());
                // 判断需不需要弹出队列
                if (nums.at(left) == my_queue.top())
                {
                    my_queue.pop();
                }
                ++left;
                --count;
            }
            ++right;
            ++count;
        }
        return value;
    }
};