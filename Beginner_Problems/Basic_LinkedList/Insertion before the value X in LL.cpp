class Solution
{
public:
    ListNode *insertBeforeX(ListNode *&head, int x, int val)
    {
        if (!head)
        {
            return head;
        }

        if (head->val == x)
        {
            return new ListNode(val, head);
        }

        ListNode *prev = NULL, *curr = head;
        ListNode *toInsert = new ListNode(val);
        while (curr)
        {
            if (curr->val == x)
            {
                toInsert->next = curr;
                prev->next = toInsert;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};