// 平衡二叉树
// 判断是否为平衡二叉树，递归
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
#include <cstdlib>
#include <algorithm>
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
private:
    int heightChild(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left_height = heightChild(root->left);
        if (left_height == -1)
        {
            return -1;
        }    
        int right_height = heightChild(root->right);
        if (right_height == -1)
        {
            return -1;
        }
        if (abs(left_height - right_height) > 1)
        {
            return -1;
        }
        else
        {
            return 1 + max(left_height, right_height);
        }
    }

public:
    bool isBalanced(TreeNode* root) 
    {
        if (heightChild(root) == -1)
        {
            return false;
        }
        return true;
    }
};