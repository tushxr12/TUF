class Solution
{
public:
    ListNode *insertBeforeHead(ListNode *head, int X)
    {

        if (!head)
        {
            return new ListNode(X);
        }
        ListNode *toInsert = new ListNode(X);
        toInsert->next = head;
        head->prev = toInsert;
        return toInsert;
    }
};