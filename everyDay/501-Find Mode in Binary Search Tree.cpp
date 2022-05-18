// 二叉搜索树中的众数
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
    TreeNode *pre = nullptr;
    vector<int> value;
    int count;
    int max;
    void traversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        traversal(root->left);
        if (pre == nullptr)
        {
            count = 1;
            max = 0;
        }
        else if (pre->val == root->val)
        {
            ++count;
        }
        else if (pre->val != root->val)
        {
            count = 1;
        }
        if (count == max)
        {
            value.push_back(root->val);
        }
        else if (count > max)
        {
            value.clear();
            value.push_back(root->val);
            max = count;
        }
        pre = root;
        traversal(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) 
    {
        traversal(root);
        return value;
    }
};