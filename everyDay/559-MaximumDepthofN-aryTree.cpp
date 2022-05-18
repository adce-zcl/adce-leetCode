// N 叉树的最大深度
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#include <vector>
using namespace std;
class Node 
{
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
class Solution 
{
private:
    int get_depth(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int cur_max = 0;
        for (size_t i = 0; i < root->children.size(); ++i)
        {
            int depth = get_depth(root->children.at(i));
            cur_max = max(cur_max, depth);
        }
        return cur_max + 1;
    }
public:
    int maxDepth(Node* root) 
    {
        return get_depth(root);
    }
};