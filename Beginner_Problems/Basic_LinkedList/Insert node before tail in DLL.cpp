class Solution
{
public:
    ListNode *insertBeforeTail(ListNode *head, int x)
    {
        ListNode *curr = head;

        if (!head)
        {
            return new ListNode(x);
        }

        while (curr->next)
        {
            curr = curr->next;
        }
        ListNode *prev = curr->prev;
        ListNode *toInsert = new ListNode(x);
        if (!prev)
        {
            toInsert->next = head;
            head->prev = toInsert;
            return toInsert;
        }
        toInsert->next = curr;
        toInsert->prev = prev;
        prev->next = toInsert;
        curr->prev = toInsert;
        return head;
    }
};