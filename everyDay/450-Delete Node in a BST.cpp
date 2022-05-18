// 删除二叉搜索树中的节点
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
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        // 如果没找到
        if (root == nullptr)
        {
            return nullptr;
        }
        // 找到了
        // 如果左右孩子都为nullptr
        if (root->val == key && root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        // 如果左孩子为空，右孩子不为空
        else if (root->val == key && root->left == nullptr)
        {
            TreeNode *right = root->right;
            delete root;
            return right;
        }
        else if (root->val == key && root->right == nullptr)
        {
            TreeNode *left = root->left;
            delete root;
            return left;
        }
        // 左右都不为空
        else if (root->val == key)
        {
            // 把root->left 拼接 到 root->right的最left上
            TreeNode *right = root->right;
            while (right->left != nullptr)
            {
                right = right->left;
            }
            right->left = root->left;
            right = root->right;
            delete root;
            return right;
        }
        
        if (root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};