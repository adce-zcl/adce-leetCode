// 二叉树的右视图
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
struct TreeNode {
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
    vector<int> rightSideView(TreeNode* root) 
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
            TreeNode *current;
            int size = que.size();
            for (int i = 0; i < size; ++i)
            {
                current = que.front();
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
            value.push_back(current->val);
        }
        return value;
    }
};