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

