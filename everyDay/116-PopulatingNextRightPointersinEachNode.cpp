// 填充每个节点的下一个右侧节点指针
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
#include <cstdlib>
#include <queue>
using namespace std;
class Node 
{
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution 
{
public:
    Node* connect(Node* root) 
    {
        if (root == nullptr)
        {
            return root;
        }
        queue<Node *> que;
        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            Node *left;
            Node *right;
            for (size_t i = 0; i < size - 1; ++i)
            {
                left = que.front();
                que.pop();
                right = que.front();
                left->next = right;
                if (left->left != nullptr)
                {
                    que.push(left->left);
                }
                if (left->right != nullptr)
                {
                    que.push(left->right);
                }
            }
            left = que.front();
            que.pop();
            left->next = nullptr;
            if (left->left != nullptr)
            {
                que.push(left->left);
            }
            if (left->right != nullptr)
            {
                que.push(left->right);
            }
        }
        return root;
    }
};