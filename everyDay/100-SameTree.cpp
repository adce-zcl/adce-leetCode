// 相同的树
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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        return sameTree(p, q);
    }
    bool sameTree(TreeNode* p, TreeNode* q)
    {
        
        if (p == nullptr && q != nullptr)
        {
            return false;
        }
        else if (p != nullptr && q == nullptr)
        {
            return false;
        }
        else if (p == nullptr && q == nullptr)
        {
            return true;
        }
        else if (p->val != q->val)
        {
            return false;
        }
        bool left = sameTree(p->left, q->left);
        bool right = sameTree(p->right, q->right);
        return left && right;
    }
};