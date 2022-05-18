// 两数相加
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
#include <vector>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode *value = new ListNode();
        ListNode *head = value->next;
        int ca = 0; // 进位为0
        while (l1 != nullptr && l2 != nullptr)
        {
            int cur_value = l1->val + l2->val + ca;
            ca = cur_value / 10;    // 新的进位
            int cur = cur_value % 10;   // 当前位的值
            ListNode *cur_node = new ListNode(cur);
            value->next = cur_node;
            value = value->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr)
        {
            int cur_value = l1->val + ca;
            ca = cur_value / 10;    // 新的进位
            int cur = cur_value % 10;   // 当前位的值
            ListNode *cur_node = new ListNode(cur);
            value->next = cur_node;
            value = value->next;
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            int cur_value = l2->val + ca;
            ca = cur_value / 10;    // 新的进位
            int cur = cur_value % 10;   // 当前位的值
            ListNode *cur_node = new ListNode(cur);
            value->next = cur_node;
            value = value->next;
            l2 = l2->next;
        }
        return head;
    }
};