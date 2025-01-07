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
    ListNode *sortList(ListNode *head) {
        int cz = 0, co = 0, ct = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            if(temp->val == 0)
                cz++;
            else if(temp->val == 1)
                co++;
            else
                ct++;
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL)
        {
            if(cz != 0)
            {
                temp->val = 0;
                cz--;
            }
            else if(co != 0)
            {
                temp->val = 1;
                co--;
            }
            else
            {
                temp->val = 2;
                ct--;
            }
            temp = temp->next;
        }
        return head;
    }
};

//Optimal
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
    ListNode *sortList(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* zeroHead = new ListNode(-1), *oneHead = new ListNode(-1), *twoHead = new ListNode(-1);
        ListNode* zero = zeroHead, *one = oneHead, *two = twoHead;

        ListNode* temp = head;

        while(temp != NULL)
        {
            if(temp->val == 0)
            {
                zero->next = temp;
                zero = zero->next;
            }
            else if(temp->val == 1)
            {
                one->next = temp;
                one = one->next;
            }
            else 
            {
                two->next = temp;
                two = two->next;
            }
            temp = temp->next;
        }
        
        zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
        one->next = (twoHead->next);
        two->next = NULL;
        ListNode* newHead = zeroHead->next;

        delete(oneHead);
        delete(zeroHead);
        delete(twoHead);

        return newHead;
    }
};
