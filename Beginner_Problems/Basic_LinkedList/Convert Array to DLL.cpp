class Solution
{
public:
    ListNode *arrayToLinkedList(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return NULL;
        }
        ListNode *head = new ListNode(nums[0]);
        ListNode *prev = head;
        for (int i = 1; i < nums.size(); i++)
        {
            ListNode *newNode = new ListNode(nums[i]);
            newNode->prev = prev;
            prev->next = newNode;
            prev = newNode;
        }
        prev->next = NULL;
        return head;
    }
};