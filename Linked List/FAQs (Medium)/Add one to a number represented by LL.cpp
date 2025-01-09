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
   private:
    ListNode* reverseLL(ListNode* head) {
        ListNode *temp = head, *prev = NULL;

        while (temp) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

   public:
    ListNode* addOne(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        int carry = 1;
        ListNode* revHead = reverseLL(head);
        ListNode* temp = revHead;

        while (temp != NULL) {
            if (carry == 0) break;

            int val = temp->val + carry;
            temp->val = (val % 10);
            carry = val / 10;
            temp = temp->next;
        }

        ListNode* origHead = reverseLL(revHead);
        if (carry == 1) {
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            return newHead;
        }
        return origHead;
    }
};
