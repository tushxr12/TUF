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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next)
        {
            delete head;
            return NULL;
        }
        int length = 0;
        ListNode* temp = head;
        while(temp)
        {
            length++;
            temp = temp->next;
        }
        temp = head;
        int steps = (length/2);

        while(steps > 0)
        {
            steps--;
            if(steps == 0)
                break;
            temp = temp->next;            
        }
        if(temp->next != NULL)
        {
            ListNode* todelete = temp->next;
            temp->next = temp->next->next;
            delete(todelete);
        }
        return head;
    }
};
