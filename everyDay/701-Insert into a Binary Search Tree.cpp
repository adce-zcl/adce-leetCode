// 叉搜索树中的插入操作
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
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        if (root == nullptr)
        {
            TreeNode *new_node = new TreeNode(val);
            return new_node;
        }
        if (val < root->val)
        {
            root->left = insertIntoBST(root->left, val);
        }
        if (val > root->val)
        {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};