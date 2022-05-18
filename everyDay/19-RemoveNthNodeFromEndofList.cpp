// 删除链表的倒数第N个结点
// 使用双链表，一趟扫描

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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        // 建立一个虚拟头
        ListNode *temp = new ListNode(-1, head);
        head = temp;
        ListNode *slow = head, *fast = head;

        for (int i = 1; i <= n; i++)
        {
            fast = fast->next;
        }
        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        // 删除slow后面的那个节点
        fast = slow->next;
        slow->next = fast->next;
        delete fast;
        // 删除虚拟头节点
        temp = head->next;
        delete head;
        head = temp;
        return head;
    }
};