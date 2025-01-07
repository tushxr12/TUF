/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        int cz = 0, co = 0, ct = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            if(temp->val == 0)
                cz++;
            else if(temp->val == 1)
                co++;
            else
                ct++;
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL)
        {
            if(cz != 0)
            {
                temp->val = 0;
                cz--;
            }
            else if(co != 0)
            {
                temp->val = 1;
                co--;
            }
            else
            {
                temp->val = 2;
                ct--;
            }
            temp = temp->next;
        }
        return head;
    }
};
