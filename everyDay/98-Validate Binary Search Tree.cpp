// 验证二叉搜索树
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
    vector<int> vec;
    // 二叉搜索树的中序遍历是递增的
    void traversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);
    }
public:
    bool isValidBST(TreeNode* root) 
    {
        long min = LONG_MIN;
        traversal(root);
        for (auto &&i : vec)
        {
            if (min < i)
            {
                min = i;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};