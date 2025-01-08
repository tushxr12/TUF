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
