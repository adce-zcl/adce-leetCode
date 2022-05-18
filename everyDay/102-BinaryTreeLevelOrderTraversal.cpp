// 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        queue<TreeNode *> que;
        vector<vector<int>> value;
        if (root == nullptr)
        {
            return value;
        }
        que.push(root);
        while (!que.empty())
        {
            vector<int> cur;
            int size = que.size();
            for (size_t i = 0; i < size; ++i)
            {
                TreeNode *current = que.front();
                cur.push_back(current->val);
                que.pop();
                if (current->left != nullptr)
                {
                    que.push(current->left);
                }
                if (current->right != nullptr)
                {
                    que.push(current->right);
                }
            }
            value.push_back(cur);
        }
        return value;
    }
};