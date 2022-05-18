// 网络中的空闲时刻
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <queue>
using namespace std;

class Solution
{


public:
    // edges：邻接表，patience：每个服务器的重发时间
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) 
    {
        // 1.先计算出，每一个服务器到0号服务器的最短路径,利用广搜
        // 构建邻接表，使用广搜
        int n = patience.size();
        vector<vector<int>> graph(n);
        for (auto &&i : edges)
        {
            graph[i.at(0)].emplace_back(i.at(1));
            graph[i.at(1)].emplace_back(i.at(0));
        }
        vector<int> dist(n);// 记录每个服务器到主服务器的最短距离
        queue<int> que;
        que.emplace(0);
        while(!que.empty()) 
        { // BFS
            int u = que.front();
            que.pop();
            for(auto& v : graph[u]) 
            {
                if(v && !dist[v]) 
                { // 新节点不是0节点，并且没有访问过
                    dist[v] = dist[u] + 1;//记录新节点的距离
                    que.emplace(v);
                }
            }
        }
        

        // 求出最大的秒数
        int minS = 0;
        for (int i = 1; i < patience.size(); i++)
        {
            int wait = patience.at(i);
            int time = 2*dist[i];
            if(wait >= time)
            {
                minS = minS > time ? minS : time;
            }
            else
            {
                int t = time + (time - 1) / wait * wait;
                minS = minS > t ? minS : t;
            }
        }
        return minS+1;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> edges{{4,6}, {1, 2},{4,5},{0,1},{2,3},{6,3},{1,8}};
    vector<int> patience{0, 2, 1};
    cout << s.networkBecomesIdle(edges, patience);
    system("pause");
    exit(0);
}