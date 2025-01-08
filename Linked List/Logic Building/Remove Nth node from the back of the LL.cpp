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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = 0;

        while(temp != NULL)
        {
            len++;
            temp = temp->next;
        }

        if(len == n){
            //Delete head
            ListNode* newHead = head->next;
            delete(head);
            return newHead;
        }

        int fromStart = len - n; // 
        temp = head;

        while(temp != NULL)
        {
            fromStart--;
            if(fromStart == 0)
                break;
            temp = temp->next;
        }

        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete(delNode);
        return head;
    }
};
