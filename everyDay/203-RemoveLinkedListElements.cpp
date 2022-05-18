// 移除链表元素

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
    struct ListNode *next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode *temp; // 辅助节点
        // 先判断头节点
        while (head != nullptr && head->val == val)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        // 判断头节点之后的节点
        if(head == nullptr)
        {
            return head;
        }
        ListNode *pre = head;
        temp = pre->next;
        while (temp != nullptr)
        {
            if(temp->val == val)
            {
                pre->next = temp->next;
                temp->next = nullptr;
                delete temp;
                temp = pre->next;
                continue;
            }
            pre = pre->next;
            temp = temp->next;
        }
        return head;
    }
};
