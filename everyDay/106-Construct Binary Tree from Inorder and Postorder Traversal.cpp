// 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if (postorder.size() == 0)
        {
            return nullptr;
        }
        int root_val = postorder.at(postorder.size() - 1);
        TreeNode *root = new TreeNode(root_val);
        if (postorder.size() == 1)
        {
            return root;    // 叶子节点
        }
        // 找到前序数组的切割点
        unsigned int root_index;
        for (root_index = 0; root_index < inorder.size(); ++root_index)
        {
            if (inorder.at(root_index) == root_val)
            {
                break;
            }
        }
        
        // 分割前序数组
        vector<int> inorder_left(inorder.begin(), inorder.begin() + root_index);
        vector<int> inorder_right(inorder.begin() + root_index + 1, inorder.end());

        // 删掉后续数组的最后一个节点
        postorder.erase(postorder.end() - 1);
        // 分割后续数组
        vector<int> postorder_left(postorder.begin(), postorder.begin() + inorder_left.size());
        vector<int> postorder_right(postorder.begin() + inorder_left.size(), postorder.end());

        root->left = buildTree(inorder_left, postorder_left);
        root->right = buildTree(inorder_right, postorder_right);

        return root;
    }
};