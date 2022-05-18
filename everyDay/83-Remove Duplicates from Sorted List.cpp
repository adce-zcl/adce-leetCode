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
private:
    ListNode* recursion(ListNode *head)
    {
        if (head->next == nullptr)
        {
            return head;
        }
        head->next = recursion(head->next);
        if (head->val == head->next->val)
        {
            ListNode *temp = head->next;
            delete head;
            return temp;
        }
        return head;
    }

public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        head = recursion(head);
        return head;
    }
};