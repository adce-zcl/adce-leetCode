// 反转一个单链表
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
    ListNode* reverseList(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        // 理论分成两条链表
        ListNode *list1 = head;
        ListNode *list2 = head->next;
        ListNode *temp;
        list1->next = nullptr;
        while(list2 != nullptr)
        {
            temp = list2->next;
            if(temp == nullptr)
            {
                list2->next = list1;
                head = list2;
                break;
            }
            list2->next = list1;
            list1 = list2;
            list2 = temp;
        }
        return head;
    }
};