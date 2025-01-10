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
    ListNode *findStartingPoint(ListNode *head) {
        map<ListNode *, int> mpp;
        ListNode *temp = head;

        while (temp != NULL) {
            if (mpp.find(temp) != mpp.end()) return temp;
            mpp.insert({temp, 1});
            temp = temp->next;
        }
        return NULL;
    }
};
