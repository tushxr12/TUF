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
    ListNode* sortList(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        sort(arr.begin(),arr.end());
        ListNode*dummyNode = new ListNode(-1);
        temp = dummyNode;

        for(int i = 0;i < arr.size();i++)
        {
            ListNode* node = new ListNode(arr[i]);
            temp->next = node;
            temp = node;
        }

        return dummyNode->next;
    }
};

