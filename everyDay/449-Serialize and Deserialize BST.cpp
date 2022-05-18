// 序列化和反序列化二叉搜索树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


// 通过前序获得序列
// 通过前序排序获得中序序列
// 通过中序序列和前序构建二叉树
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Codec 
{
private:
    
    TreeNode* getTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0)   // 头节点为空
        {
            return nullptr;
        }
        int rootVal = preorder.at(0);
        TreeNode *root = new TreeNode(rootVal);
        if (preorder.size() == 1)
        {
            return root;
        }
        // 从中序遍历数组里找到头节点的下标
        int rootIndex;
        for (rootIndex = 0; rootIndex < inorder.size(); ++rootIndex)
        {
            if (inorder.at(rootIndex) == preorder.at(0))
            {
                break;
            }
        }
        // 切分中序数组
        vector<int> inorder_left(inorder.begin(), inorder.begin() + rootIndex);
        vector<int> inorder_right(inorder.begin() + rootIndex + 1, inorder.end());
        // 切分前序数组
        preorder.erase(preorder.begin());
        vector<int> preoder_left(preorder.begin(), preorder.begin() + inorder_left.size());
        vector<int> preoder_right(preorder.begin() + inorder_left.size(), preorder.end());

        // 递归
        root->left = getTree(preoder_left, inorder_left);
        root->right = getTree(preoder_right, inorder_right);
        return root;
    }

    void preorderTree(vector<int> &preorder, TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        int val = root->val;
        preorder.push_back(val);
        preorderTree(preorder, root->left);
        preorderTree(preorder, root->right);
        return;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        vector<int> preorder;
        string ans;
        preorderTree(preorder, root);
        for (int i = 0; i < preorder.size(); ++i)
        {
            ans += to_string(preorder.at(i)) + '.';
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    // 1234.2223.456.456.456.
    TreeNode* deserialize(string data) 
    {
        string tmp = "";
        vector<int> preorder;
        vector<int> inorder;
        for (int i = 0; i < data.size(); ++i)
        {
            if (data.at(i) != '.')
            {
                tmp.push_back(data.at(i));
            }
            else
            {
                preorder.push_back(stoi(tmp));
                tmp.clear();
            }
        }
        inorder = preorder;
        sort(inorder.begin(), inorder.end());
        return getTree(preorder, inorder);
    }
};

int main()
{
    Codec c;
}