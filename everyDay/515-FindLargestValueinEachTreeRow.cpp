// 在每个树行中找最大值
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <queue>
#include <climits>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution 
{
public:
    vector<int> largestValues(TreeNode* root) 
    {
        vector<int> value;
        if (root == nullptr)
        {
            return value;
        }
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            int cur_max = INT_MIN;
            TreeNode *cur;
            int size = que.size();
            for (size_t i = 0; i < size; ++i)
            {
                cur = que.front();
                que.pop();
                cur_max = max(cur_max, cur->val);
                if (cur->left != nullptr)
                {
                    que.push(cur->left);
                }
                if (cur->right != nullptr)
                {
                    que.push(cur->right);
                }
            }
            value.push_back(cur_max);
        }
        return value;
    }
};