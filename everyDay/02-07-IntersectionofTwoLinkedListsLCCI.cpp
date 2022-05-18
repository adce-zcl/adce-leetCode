// 链表相交

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if(headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        ListNode *tempA = headA, *tempB = headB;
        int length_sub = 0; // 两个链表的长度差
        char c;
        while (true)
        {
            if(tempA->next == nullptr)  // 链表A到了结尾,B更长
            {
                while(tempB->next != nullptr)
                {
                    tempB = tempB->next;
                    ++length_sub;
                }
                c = 'B';
                break;
            }
            else if(tempB->next == nullptr) // 链表B到了结尾，A更长
            {
                while(tempA->next != nullptr)
                {
                    tempA = tempA->next;
                    ++length_sub;
                }
                c = 'A';
                break;
            }
            tempA = tempA->next;
            tempB = tempB->next;
        }
        tempA = headA;
        tempB = headB;
        if(c == 'A')    // A比B长length_sub
        {
            for (int i = 0; i < length_sub; i++)
            {
                tempA = tempA->next;
            }
        }
        else
        {
            for (int i = 0; i < length_sub; i++)
            {
                tempB = tempB->next;
            }
        }
        while (tempA != tempB && tempA != nullptr && tempB != nullptr)
        {
            tempA = tempA->next;
            tempB = tempB->next;
        }
        if(tempA == nullptr || tempB == nullptr)
        {
            return nullptr;
        }
        else
        {
            return tempA;
        }
    }
};