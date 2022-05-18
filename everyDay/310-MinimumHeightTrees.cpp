// 最小高度树
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
// height0 表示子树高
// height 表示树高

// 动态规划
class Solution 
{
public:
    // dfs1 计算以 0 号节点为根的树中，以各个节点为根的子树高
    void dfs1(vector<vector<int>>& graph, vector<int>& height0, int u) 
    {
        height0[u] = 1;
        int h = 0;
        for (int v : graph[u]) {
            if (height0[v] != 0) continue;
            dfs1(graph, height0, v);
            h = max(h, height0[v]);
        }
        height0[u] = h + 1;
    }

    // dfs2 进行换根动态规划，计算出所有的树高
    void dfs2(vector<vector<int>>& graph, vector<int>& height0, vector<int>& height, int u) 
    {
        // 计算子树高的最大值和次大值
        int first = 0;
        int second = 0;
        for (int v : graph[u]) {
            if (height0[v] > first) 
            {
                second = first;
                first = height0[v];
            } else if (height0[v] > second)
                second = height0[v];
        }
        height[u] = first + 1;
        for (int v : graph[u]) {
            // 树高已计算，跳过这个节点
            if (height[v] != 0) continue;
            // 更新以当前节点为根的子树高，换根到 v
            height0[u] = (height0[v] != first ? first : second) + 1;
            // 递归进行换根动态规划
            dfs2(graph, height0, height, v);
        }
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        vector<vector<int>> graph(n);
        for (const auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> height0(n, 0);
        vector<int> height(n, 0);
        dfs1(graph, height0, 0);
        dfs2(graph, height0, height, 0);
        vector<int> ans;
        int h = n;
        for (int i = 0;i < n;++i) {
            if (height[i] < h) {
                h = height[i];
                ans.clear();
            }
            if (height[i] == h)
                ans.push_back(i);
        }
        return ans;
    }
};

// 作者：vclip
// 链接：https://leetcode-cn.com/problems/minimum-height-trees/solution/c-huan-gen-by-vclip-sa84/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// 官方解体，最小高度的根节点，就是距离最长的两个节点的中点
class Solution {
public:
    void dfs(int u, vector<int> & dist, vector<int> & parent, const vector<vector<int>> & adj) {
        // 遍历所有与u相连的节点
        for (auto & v : adj[u]) {
            // 如果这个节点没有被访问过
            if (dist[v] < 0) {
                // 这个节点到u点的距离等于u点到u点的距离+1
                dist[v] = dist[u] + 1;
                // 这个节点的父节点是u节点
                parent[v] = u;
                // 递归遍历和这个节点相邻的所有节点。
                dfs(v, dist, parent, adj); 
            }
        }
    }

    int findLongestNode(int u, vector<int> & parent, const vector<vector<int>> & adj) 
    {
        int n = adj.size();
        // 存储每一个节点到u节点的距离
        vector<int> dist(n, -1);
        // u节点到自己本身的距离是0
        dist[u] = 0;
        // 通过深搜填充距离数组
        dfs(u, dist, parent, adj);
        int maxdist = 0;
        int node = -1;
        for (int i = 0; i < n; i++) {
            if (dist[i] > maxdist) {
                maxdist = dist[i];
                node = i;
            }
        }
        // 返回拥有最大距离的节点
        return node;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        if (n == 1) 
        {
            return {0};
        }
        // 路径矩阵
        vector<vector<int>> adj(n);
        for (auto & edge : edges) {
            adj[edge[0]].emplace_back(edge[1]);
            adj[edge[1]].emplace_back(edge[0]);
        }
        // 存储每一个节点的直接父节点
        vector<int> parent(n, -1);
        /* 找到距离节点 0 最远的节点  x */
        int x = findLongestNode(0, parent, adj);
        /* 找到距离节点 x 最远的节点  y */
        int y = findLongestNode(x, parent, adj);
        /* 找到节点 x 到节点 y 的路径 */
        vector<int> path;
        // y顺着x的路径一定能找到x，所以先把x设置-1
        parent[x] = -1;
        // 还没到x
        while (y != -1) {
            path.emplace_back(y);
            // 顺着往上找父节点，一直到x
            y = parent[y];
        }
        int m = path.size();
        if (m % 2 == 0) {
            return {path[m / 2 - 1], path[m / 2]};
        } else {
            return {path[m / 2]};
        }
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/minimum-height-trees/solution/zui-xiao-gao-du-shu-by-leetcode-solution-6v6f/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。