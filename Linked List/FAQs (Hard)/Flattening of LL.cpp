/*
Definition of special linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next1;
    }
};
*/

class Solution {
private:
    ListNode* arrToLinkedList(vector<int> &arr)
    {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        for(int i = 0;i < arr.size();i++)
        {
            temp->child = new ListNode(arr[i]);
            temp = temp->child;
        }
        return dummyNode->child;
    }
public:
    ListNode* flattenLinkedList(ListNode* &head) {
        vector<int> arr;
        ListNode* temp = head;

        while(temp != NULL)
        {
            ListNode* t2 = temp;

            while(t2 != NULL)
            {
                arr.push_back(t2->val);
                t2 = t2->child;
            }

            temp = temp->next;
        }

        sort(arr.begin(), arr.end());
        return arrToLinkedList(arr);
    }
};
