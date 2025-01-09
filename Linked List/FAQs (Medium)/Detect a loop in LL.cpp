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
    bool hasCycle(ListNode* head) {
        map<ListNode*, int> mpp;
        ListNode* temp = head;
        mpp[temp] = 1;

        while (temp != NULL) {
            temp = temp->next;
            if (mpp.find(temp) != mpp.end()) return true;
            mpp.insert({temp, 1});
        }
        return false;
    }
};
