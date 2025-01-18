//Brute
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

//Optimized
class Solution {
private:
    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while(list1 != NULL && list2 != NULL)
        {
            if(list1->val < list2->val)
            {
                temp->child = list1;
                temp = list1;
                list1 = list1->child;
            }
            else
            {
                temp->child = list2;
                temp = list2;
                list2 = list2->child;
            }
            temp->next = nullptr;
        }
        if(list1)
            temp->child = list1;
        if(list2)
            temp->child = list2;
        if(dummyNode->child)
            dummyNode->child->next = nullptr;
        return dummyNode->child;
    }
public:
    ListNode* flattenLinkedList(ListNode* &head) {
         if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* mergeHead = flattenLinkedList(head->next);
        head = merge(head, mergeHead);
        return head;
    }
};
