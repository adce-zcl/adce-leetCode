// 找到处理最多请求的服务器
// 最繁忙的服务器定义为处理最多请求的
#include <vector>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

// 超时了
#if 0
class Solution 
{
private:
    struct Server
    {
        // int index;      // 服务器编号 0 - k-1
        // bool status;    // 服务器状态，0 free；1 busy
        int over_time;  // 该服务器到第几秒能结束忙碌:完成任务的时间 = 任务到来的时间+任务加载需要的时间
        int work_num;   // 处理的请求的数量
        Server() : over_time(0), work_num(0){}
    };
    vector<Server> Servers;
    int k;
    // 服务器容器初始化,容器下标为服务器编号
    void init_servers(const int &k)
    {
        for (int i = 0; i < k; ++i)
        {
            Servers.push_back(Server());
        }
    }

    /**
     * @brief 
     * 寻找空闲的服务器,并交付任务，如果没有空闲的服务器，任务丢弃
     * 
     * @param arrival 
     * 第arrival秒到来的任务
     * 
     * @param load 
     * 该任务需要加载load长的时间
     */

    void find_free_server(const int &index, const int &arrival, const int &load)
    {
        // 往前走时间线
        for (int i = 0; i < k; ++i)
        {
            // 第arrival刻时间的任务到了,说明此时此刻整个时间线往前走到了第arrival秒
            //Servers.at(i).over_time -= arrival;
            if(Servers.at(i).over_time - arrival <= 0)  // 这个服务器的任务已经完成了
            {
                Servers.at(i).over_time = 0;
            }
        }

        // 寻找空闲服务器
        for (int i = index % k, num = 0; num < k; ++i, ++num)
        {
            if(i == k)
            {
                i = 0;
            }
            if (Servers.at(i).over_time == 0)  // 空闲服务器
            {
                // 交付任务
                Servers.at(i).over_time = arrival + load;
                ++Servers.at(i).work_num;
                // 直接返回
                return;
            }
        }
        // 没找到空闲服务器
        return;
    }

public:
    vector<int> busiestServers(int _k, vector<int>& arrival, vector<int>& load) 
    {
        k = _k;
        init_servers(k);
        for (int i = 0; i < arrival.size(); ++i)
        {
            find_free_server(i, arrival.at(i), load.at(i));
        }
        // 找出服务器中work_num最大的几个
        vector<int> value;
        int max_num = 0;
        for (int i = 0; i < k; i++)
        {
            if (Servers.at(i).work_num > max_num)
            {
                value.clear();
                max_num = Servers.at(i).work_num;
                value.push_back(i);
            }
            else if (Servers.at(i).work_num == max_num)
            {
                value.push_back(i);
            }
        }
        return value;
    }
};
#endif
// 对Solution的改进，使用优先级队列，把循环寻找，做成堆排序
class Solution
{
private:
    set<int> free_servers;              // 空闲的服务器，有序集合
    // 正在工作的服务器，按照完成任务的时间点排序
    // 第一个int：任务完成的时间；第二个int：服务器下标
    // 按照任务完成得时间排序，越早得排序越往前
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> work_servers;
    vector<int> nums_servers;           // 每个服务器处理请求的数

public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) 
    {
        for (int i = 0; i < k; ++i)
        {
            free_servers.insert(i);     // 初始化服务器
            nums_servers.push_back(0);  // 起初每个服务器处理的请求数量是0
        }

        // 循环处理第i个请求，第i个请求在第arrival[i]时刻到达
        for (int i = 0; i < arrival.size(); ++i)
        {
            // 到达了第arrival[i]时刻，查看工作队列中是否有服务器完成工作，进入空闲队列
            while (!work_servers.empty() && work_servers.top().first <= arrival.at(i))
            {
                free_servers.insert(work_servers.top().second);     // 把该服务器移动至空闲集合
                work_servers.pop();     // 弹出队首服务器
            }

            // 如果空闲服务器队列为空，直接跳过
            if (free_servers.empty())
            {
                continue;
            }

            // 这里必须是服务器去找工作，不能是工作来找服务器，要不然服务器太多了会超时
            int index = i % k;
            auto pos = free_servers.lower_bound(index);
            if( pos == free_servers.end())  // 找出首个大于等于index 的服务器
            {
                pos = free_servers.begin(); // 如果没有，那么就取集合头就可以了
            }
            int over_time = arrival.at(i) + load.at(i);     // 该工作完成的时刻
            // 把该服务器移动到工作队列
            work_servers.emplace(over_time, *pos);
            // 该服务器的处理的请求数量加1
            ++nums_servers.at(*pos);
            // 把该服务器从空闲集合里移除
            free_servers.erase(pos);
        }
        
        // 从nums_servers中找出最大的一组
        int temp_max = 0;
        vector<int> value;
        for (int i = 0; i < nums_servers.size(); ++i)
        {
            if(nums_servers.at(i) > temp_max)
            {
                value.clear();
                temp_max = nums_servers.at(i);
                value.push_back(i);
            }
            else if (nums_servers.at(i) == temp_max)
            {
                value.push_back(i);
            }
        }
        return value;
    }
};

int main()
{
    vector<int> arrival{1,2,3,4,8,9,10};
    vector<int> load{5,2,10,3,1,2,2};
    int k = 3;
    Solution s;
    vector<int> value;
    value = s.busiestServers(k, arrival, load);
    for (auto &&i : value)
    {
        cout << i << " ";
    }
    system("pause");
}