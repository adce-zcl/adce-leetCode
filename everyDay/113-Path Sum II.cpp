// 路径总和 II
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
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>> value;
        if (root == nullptr)
        {
            return value;
        }
        vector<int> cur;
        path(root, targetSum, cur, value);
        return value;
    }
    void path(TreeNode *root, int target_sum, vector<int> &cur, vector<vector<int>> &value)
    {
        if (target_sum - root->val == 0 && root->left == nullptr && root->right == nullptr)
        {
            cur.push_back(root->val);
            value.push_back(cur);
            return;
        }
        cur.push_back(root->val);
        if (root->left != nullptr)
        {
            path(root->left, target_sum - root->val, cur, value);
            cur.pop_back(); // 回溯
        }
        if (root->right != nullptr)
        {
            path(root->right, target_sum - root->val, cur, value);
            cur.pop_back(); // 回溯
        }
        return;
    }
};