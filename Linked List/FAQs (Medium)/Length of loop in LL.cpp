//Brute
class Solution {
public:
    int findLengthOfLoop(ListNode *head) {
        map<ListNode*,int> mpp;
        ListNode* temp = head;
        int i = 1;
        while(temp != NULL)
        {
            if(mpp.find(temp) != mpp.end())
            {
                int val = mpp[temp];
                return (i - val);
            }
            mpp.insert({temp,i});
            i++;
            temp = temp->next;
        }
        return 0l;
    }
};

//Optimized
class Solution {
private:
    int findLength(ListNode* slow, ListNode* fast)
    {
        int length = 1;
        fast = fast->next;
        while(fast != slow)
        {
            fast = fast->next;
            length++;
        }
        return length;
    }
public:
    int findLengthOfLoop(ListNode *head) {
        ListNode* slow = head, *fast = head;

        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
            {
                return findLength(slow, fast);
            }
        }
        return 0;
    }
};
