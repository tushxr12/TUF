//Brute (Modifying data directly)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        while(temp != NULL)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }

        int i = v.size() - 1;
        temp = head;
        while(temp != NULL)
        {
            temp->val = v[i];
            i--;
            temp = temp->next;
        }
        return head;
    }
};

//Better (Modifying Links)
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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head, *prev = NULL;
        while(temp != NULL)
        {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
};
