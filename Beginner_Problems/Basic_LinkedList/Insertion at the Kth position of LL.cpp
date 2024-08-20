class Solution
{
public:
    ListNode *insertAtKthPosition(ListNode *&head, int x, int k)
    {
        if (head == NULL && k == 1)
        {
            if (k == 1)
            {
                return new ListNode(x);
            }
            else
            {
                return head;
            }
        }

        if (k == 1)
        {
            return new ListNode(x, head);
        }

        int cnt = 0;
        ListNode *curr = head;

        while (curr)
        {
            cnt++;
            if (cnt == k - 1)
            {
                ListNode *toInsert = new ListNode(x, curr->next);
                curr->next = toInsert;
                break;
            }
            curr = curr->next;
        }
        return head;
    }
};