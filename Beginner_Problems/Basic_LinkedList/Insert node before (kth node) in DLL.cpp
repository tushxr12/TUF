class Solution
{
public:
    ListNode *insertBeforeKthPosition(ListNode *head, int x, int k)
    {
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
        ListNode *prev = curr->prev, *next = curr->next;
        ListNode *toInsert = new ListNode(x);
        if (!prev && !next)
        {
            toInsert->next = head;
            head->prev = toInsert;
            return toInsert;
        }
        else if (!prev)
        {
            toInsert->next = curr;
            curr->prev = toInsert;
            return toInsert;
        }
        else
        {
            toInsert->next = curr;
            toInsert->prev = prev;
            curr->prev = toInsert;
            prev->next = toInsert;
            return head;
        }
        return head;
    }
};