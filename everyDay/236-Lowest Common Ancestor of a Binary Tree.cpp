// 二叉树的最近公共祖先
// 递归算法
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 退出条件
        if (root == p || root == q || root == nullptr) {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        // 如果这个root节点就是最小公共节点，说明left和right肯定已经找到了
        if (left != nullptr && right != nullptr) {
            return root;    // 返回公共节点
        }
        if (left != nullptr) {
            return left;
        }
        if (right != nullptr) {
            return right;
        }
        return nullptr;
    }
};