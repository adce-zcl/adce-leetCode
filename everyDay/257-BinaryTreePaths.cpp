// 二叉树的所有路径
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
#include <string>
using namespace std;
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
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> value;
        string paths = "";
        treePaths(root, paths, value);
        return value;
    }
    void treePaths(TreeNode *root, string paths, vector<string> &value)
    {
        if (paths == "")
        {
            paths = to_string(root->val);
        }
        else
        {
            paths = paths + "->" + to_string(root->val);
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            
            value.push_back(paths);
            return ;
        }
        if (root->left != nullptr)
        {
            treePaths(root->left, paths, value);
        }
        if (root->right != nullptr)
        {
            treePaths(root->right, paths, value);
        }
        
    }
};