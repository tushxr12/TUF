class Solution
{
public:
    ListNode *deleteKthElement(ListNode *head, int k)
    {
        if (!head)
        {
            return NULL;
        }

        ListNode *curr = head;
        int cnt = 0;
        while (curr)
        {
            cnt++;
            if (cnt == k)
            {
                break;
            }
            curr = curr->next;
        }
        if (!curr)
        {
            return head;
        }
        ListNode *prev = curr->prev;
        ListNode *next = curr->next;

        if (!prev && !next)
        {
            free(curr);
            return NULL;
        }
        else if (!prev)
        {
            head = next;
            next->prev = NULL;
            return head;
        }
        else if (!next)
        {
            prev->next = NULL;
        }
        else
        {
            prev->next = next;
            next->prev = prev;
            curr->next = NULL;
            curr->prev = NULL;
            free(curr);
            return head;
        }
        return head;
    }
};