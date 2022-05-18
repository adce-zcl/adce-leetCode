// 找树左下角的值
// 层序遍历
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
#include <cstdlib>
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
    int findBottomLeftValue(TreeNode* root) 
    {
        queue<TreeNode *> que;
        que.push(root);
        int cur;
        while (!que.empty())
        {
            int size = que.size();
            cur = que.front()->val;
            for (unsigned i = 0; i < size; ++i)
            {
                TreeNode *cur_node = que.front();
                que.pop();
                if (cur_node->left != nullptr)
                {
                    que.push(cur_node->left);
                }
                if (cur_node->right != nullptr)
                {
                    que.push(cur_node->right);
                }
            }
        }
        return cur;
    }
};