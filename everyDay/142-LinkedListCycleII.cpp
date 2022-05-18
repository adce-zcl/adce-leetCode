// 环形链表II
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution 
{
public:
    ListNode *detectCycle(ListNode *head) 
    {
        ListNode *fast = head, *slow = head;
        do
        {
            if(fast == nullptr || fast->next == nullptr || fast->next->next == nullptr)
            {
                return nullptr; // 没有环
            }
            slow = slow->next;
            fast = fast->next->next;
        } while (fast != slow);
        // fast == slow
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};