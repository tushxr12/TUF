class Solution
{
public:
    ListNode *deleteTail(ListNode *head)
    {
        if (!head || !head->next)
        {
            return NULL;
        }

        ListNode *curr = head;
        while (curr->next)
        {
            curr = curr->next;
        }
        ListNode *prev = curr->prev;
        prev->next = NULL;
        free(curr);
        return head;
    }
};