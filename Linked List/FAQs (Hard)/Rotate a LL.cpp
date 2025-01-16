class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
        
        for(int i = 0;i < k;i++)
        {
            ListNode* temp = head;
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }

            ListNode* lastNode = temp->next;
            temp->next = NULL;
            lastNode->next = head;
            head = lastNode;
        }
        return head;
    }
};

//Better
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* temp = head;
        int length = 1;
        while(temp->next != NULL)
        {
            ++length;
            temp = temp->next;
        }

        temp->next = head;
        k %= length;
        int diff = length - k;

        while(diff-- > 0)
        {
            temp = temp->next;
        }

        head = temp->next;
        temp->next = nullptr;

        return head;
    }
};
