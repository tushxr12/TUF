class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1, *temp2 = list2;
        vector<int> temp;

        while(temp1 != NULL)
        {
            temp.push_back(temp1->val);
            temp1 = temp1->next;
        }

        while(temp2 != NULL)
        {
            temp.push_back(temp2->val);
            temp2 = temp2->next;
        }

        sort(temp.begin(), temp.end());
        ListNode* newHead = new ListNode(-1);
        ListNode* tempp = newHead;
        for(int i = 0;i < temp.size();i++)
        {
            ListNode* node = new ListNode(temp[i]);
            tempp->next = node;
            tempp = tempp->next;
        }
        return newHead->next;
        
    }
};

//Optimized
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1, *t2 = list2;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(t1 != NULL && t2 != NULL)
        {
            if(t1->val < t2->val)
            {
                temp->next = t1;
                t1 = t1->next;
            }
            else
            {
                temp->next = t2;
                t2 = t2->next;
            }
            temp = temp->next;
        }

        if(t1 != NULL)
        {
            temp->next = t1;
        }

        if(t2 != NULL)
        {
            temp->next = t2;
        }
        return dummyNode->next;
    }
};
