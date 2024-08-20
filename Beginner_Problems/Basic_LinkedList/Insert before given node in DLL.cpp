class Solution
{
public:
    void insertBeforeGivenNode(ListNode *node, int x)
    {
        ListNode *prev = node->prev;
        ListNode *toInsert = new ListNode(x);
        if (!prev && !node->next)
        {
            toInsert->next = node;
            node->prev = toInsert;
        }
        else if (!prev)
        {
            toInsert->next = node;
            node->prev = toInsert;
        }
        else
        {
            toInsert->next = node;
            toInsert->prev = prev;
            prev->next = toInsert;
            node->prev = toInsert;
        }
    }
};