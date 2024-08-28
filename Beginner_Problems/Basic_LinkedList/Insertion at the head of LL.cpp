class Solution
{
public:
    ListNode *insertAtHead(ListNode *&head, int X)
    {
        ListNode *toInsert = new ListNode(X);

        if (!head)
        {
            return toInsert;
        }

        toInsert->next = head;
        // head = head->next;
        return toInsert;
    }
};