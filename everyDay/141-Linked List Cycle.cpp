// 环形链表
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
    bool hasCycle(ListNode *head) 
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast != nullptr)
        {
            if (fast->next == nullptr)
            {
                break;
            }
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                return true;
            }
        }
        return false;
    }
};