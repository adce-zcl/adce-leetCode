// 二叉树的最小深度
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
    int minDepth(TreeNode* root) 
    {
        int min_layer = 0;
        if (root == nullptr)
        {
            return min_layer;
        }
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            ++min_layer;
            for (size_t i = 0; i < size; ++i)
            {
                TreeNode *cur = que.front();
                que.pop();
                if (cur->left == nullptr && cur->right == nullptr)
                {
                    return min_layer;
                }
                if (cur->left != nullptr)
                {
                    que.push(cur->left);
                }
                if (cur->right != nullptr )
                {
                    que.push(cur->right);
                }
            }
        }
        return min_layer;
    }
};