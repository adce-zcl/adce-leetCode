// 二叉树的最大深度
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
#include <queue>
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
    int maxDepth(TreeNode* root) 
    {
        int layer = 0;
        if (root == nullptr)
        {
            return layer;
        }
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            for (size_t i = 0; i < size; ++i)
            {
                TreeNode *cur = que.front();
                que.pop();
                if (cur->left != nullptr)
                {
                    que.push(cur->left);
                }
                if (cur->right != nullptr)
                {
                    que.push(cur->right);
                }
            }
            ++layer;
        }
        return layer;
    }
};