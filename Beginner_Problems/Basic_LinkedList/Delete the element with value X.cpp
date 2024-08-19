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

class Solution
{
public:
    ListNode *deleteNodeWithValueX(ListNode *&head, int x)
    {
        if (!head)
            return head;

        ListNode *curr = head, *prev = NULL;

        if (curr->val == x)
        {
            head = head->next;
            free(curr);
            return head;
        }

        while (curr)
        {
            if (curr->val == x)
            {
                if (prev->next->next == NULL)
                {
                    prev->next = NULL;
                }
                else
                    prev->next = curr->next;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        free(curr);
        return head;
    }
};