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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,int> mpp;

        ListNode* temp1 = headA, *temp2 = headB;

        while(temp1 != NULL)
        {
            mpp.insert({temp1, 1});
            temp1 = temp1->next;
        }

        while(temp2 != NULL)
        {
            if(mpp.find(temp2) != mpp.end())
                return temp2;
            temp2 = temp2->next;
        }
        return NULL;
    }
};
