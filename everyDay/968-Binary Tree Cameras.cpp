// 监控二叉树
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
private:
    int result = 0;
    // 定义状态 0 无覆盖， 1 有摄像头，2 有覆盖
    // 后序遍历，从低往上
    int traversal(TreeNode *root)
    {
        if (root == nullptr)    // 空节点认为是已经被覆盖的节点，最节省摄像头
        {
            return 2;
        }
        int left = traversal(root->left);   // 左
        int right = traversal(root->right); // 右
        // 中

        // 左右节点都有覆盖
        if (left == 2 && right == 2)
        {
            // 当前节点应该是无覆盖
            return 0;
        }

        // 左右节点有一个无覆盖，那么当前节点就得防止摄像头
        if (left == 0 || right == 0)
        {
            ++result;
            return 1;
        }

        // 左右节点有一个有摄像头,那么当前节点就一定是被覆盖的
        if (left == 1 || right == 1)
        {
            return 2;
        }

        // 执行不到，上面已经是全部的情况了。
        return 0;
    }

public:
    
    int minCameraCover(TreeNode* root) 
    {
        int isroot = traversal(root);
        if (isroot == 0)
        {
            // 根节点没有被覆盖，就需要再加一个摄像头
            ++result;
        }
        return result;
    }
};