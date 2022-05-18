/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <stack>
using namespace std;
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution 
{
public:
    bool isPalindrome(ListNode* head) 
    {
        ListNode *index = head;
        int num = 0;
        while (index != nullptr)
        {
            ++num;
            index = index->next;
        }
        if (num == 1)
        {
            return true;
        }
        int count = num / 2;  // 栈的容量
        index = head;
        stack<int> st;
        while (true)
        {
            // 入栈
            st.push(index->val);
            // 容量-1
            --count;
            // 如果容量用完退出
            index = index->next;
            if (count == 0)
            {
                break;
            }
        }
        if (num % 2 != 0)
        {
            index = index->next;
        }
        while (index != nullptr)
        {
            if (!st.empty() && index->val == st.top())
            {
                index = index->next;
                st.pop();
            }
            else
            {
                return false;
            }
        }
        if (!st.empty() || index != nullptr)
        {
            return false;
        }
        return true;
    }
};