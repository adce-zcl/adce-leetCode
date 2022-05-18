// 叉搜索树的最小绝对差
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
#include <cstdlib>
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
    // 使用辅助数组
    int getMinimumDifference1(TreeNode* root) 
    {
        traversal(root);
        
        int min_sub = INT_MAX;
        for (size_t i = 1; i < vec.size(); ++i)
        {
            int cur = abs(vec.at(i) - vec.at(i - 1));
            if ( cur < min_sub)
            {
                min_sub = cur;
            }
        }
        return min_sub;
    }
};

class Solution 
{
private:
    TreeNode *pre;
    int result = INT_MAX;
    void traversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        traversal(root->left);
        if (pre != nullptr)
        {
            result = min(result, abs(root->val - pre->val));
        }
        traversal(root->right);
    }

public:
    // 使用递归
    int getMinimumDifference1(TreeNode* root) 
    {
        traversal(root);
        return result;
    }
};