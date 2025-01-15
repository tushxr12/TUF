// Definition of singly linked list:
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int data1)
//     {
//         val = data1;
//         next = NULL;
//     }
//     ListNode(int data1, ListNode *next1)
//     {
//         val = data1;
//         next = next1;
//     }
// };

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
