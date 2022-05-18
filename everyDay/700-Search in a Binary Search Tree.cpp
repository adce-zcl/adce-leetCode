// 二叉搜索树中的搜索
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
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        if (root == nullptr || root->val == val)
        {
            return root;
        }
        else if (root->val < val)
        {
            return searchBST(root->right, val);
        }
        else if (root->val > val)
        {
            return searchBST(root->left, val);
        }
        return nullptr;
    }
};