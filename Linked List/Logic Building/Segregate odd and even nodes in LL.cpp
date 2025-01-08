//Intiutive
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* temp = head;
        vector<int> v;

        while(temp != NULL && temp->next != NULL)
        {
            v.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp) 
            v.push_back(temp->val);
        temp = head->next;
        while(temp != NULL && temp->next != NULL)
        {
            v.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp) 
            v.push_back(temp->val);
        int i = 0;
        temp = head;
        while(temp)
        {
            temp->val = v[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};
