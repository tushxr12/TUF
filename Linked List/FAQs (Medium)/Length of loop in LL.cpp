/*
Definition of singly linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};
*/

class Solution {
public:
    int findLengthOfLoop(ListNode *head) {
        map<ListNode*,int> mpp;
        ListNode* temp = head;
        int i = 1;
        while(temp != NULL)
        {
            if(mpp.find(temp) != mpp.end())
            {
                int val = mpp[temp];
                return (i - val);
            }
            mpp.insert({temp,i});
            i++;
            temp = temp->next;
        }
        return 0l;
    }
};
