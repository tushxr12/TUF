/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1, *t2 = l2;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;
        int carry = 0;

        while(t1 != NULL || t2 != NULL)
        {
            int sum = carry;
            if(t1)  
                sum += t1->val;
            if(t2)
                sum += t2->val;
            
            ListNode* newNode = new ListNode(sum%10);
            carry = sum / 10;

            curr->next = newNode;
            curr = curr->next;

            if(t1)
                t1 = t1->next;
            if(t2)
                t2 = t2->next;
        }

        if(carry)
        {
            ListNode* newNode = new ListNode(carry);
            curr->next = newNode;
            curr = curr->next;
        }
        return dummyNode->next;
    }
};
