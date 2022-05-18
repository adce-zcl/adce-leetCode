// 两两交换表中的节点

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
    ListNode* swapPairs(ListNode* head) 
    {
        // 空指针，或者只有一个节点
        if(head == nullptr || head->next == nullptr)    
        {
            return head;
        }
        // 给链表装一个虚拟头节点
        ListNode *temp = new ListNode(-1, head);
        head = temp;
        // 常规处理
        ListNode *left, *right;   
        left = head->next;
        right = left->next;
        while (true)
        {
            // 交换两个节点
            temp->next = right;
            left->next = right->next;
            right->next = left;
            temp = left;
            if(temp->next == nullptr || temp->next->next == nullptr)
            {
                break;
            }
            else
            {
                left = temp->next;
                right = left->next;
            }
        }
        // 掐除虚表头
        temp = head->next;
        delete head;
        head = temp;
        return head;
    }
};