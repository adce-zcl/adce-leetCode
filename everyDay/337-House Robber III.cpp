// 打家劫舍 III
// 树形DP
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
private:
    vector<int> backTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {0, 0};
        }
        // 0:不偷当前节点的最大金钱，1：偷当前节点的最大金钱
        vector<int> left = backTraversal(root->left);
        vector<int> right = backTraversal(root->right);
        // 偷当前节点
        int val1 = root->val + left.at(0) + right.at(0);
        // 不偷当前节点
        int val2 = max(left.at(0), left.at(1)) + max(right.at(0), right.at(1));

        return {val1, val2};
    }
public:
    int rob(TreeNode* root) 
    {
        vector<int> value = backTraversal(root);
        return max(value.at(0), value.at(1));
    }
};