// 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if (preorder.size() == 0)
        {
            return nullptr;
        }
        int root_val = preorder.at(0);
        TreeNode *root = new TreeNode(root_val);
        if (preorder.size() == 1)
        {
            return root;
        }

        int root_index;
        for ( root_index = 0; root_index < inorder.size(); ++root_index)
        {
            if (inorder.at(root_index) == root_val)
            {
                break;
            }
        }
        
        // 切分中序数组
        vector<int> inorder_left(inorder.begin(), inorder.begin() + root_index);
        vector<int> inorder_right(inorder.begin() + root_index + 1, inorder.end());

        // 切分前序数组
        preorder.erase(preorder.begin());
        vector<int> preorder_left(preorder.begin(), preorder.begin() + inorder_left.size());
        vector<int> preorder_right(preorder.begin() + preorder_left.size(), preorder.end());

        root->left = buildTree(preorder_left, inorder_left);
        root->right = buildTree(preorder_right, inorder_right);
        return root;
    }
};