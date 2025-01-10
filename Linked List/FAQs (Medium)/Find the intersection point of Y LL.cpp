class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,int> mpp;

        ListNode* temp1 = headA, *temp2 = headB;

        while(temp1 != NULL)
        {
            mpp.insert({temp1, 1});
            temp1 = temp1->next;
        }

        while(temp2 != NULL)
        {
            if(mpp.find(temp2) != mpp.end())
                return temp2;
            temp2 = temp2->next;
        }
        return NULL;
    }
};

//Better
class Solution {
private:
    ListNode* collisionPoint(ListNode* temp1, ListNode*temp2, int diff)
    {
        while(diff)
        {
            diff--;
            temp2 = temp2->next;
        }
        while(temp1 != temp2)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2 = 0;
        ListNode* temp1 = headA, *temp2 = headB;
        while(temp1)
        {
            len1++;
            temp1 = temp1->next;
        }
        while(temp2)
        {
            len2++;
            temp2 = temp2->next;
        }
        int diff = abs(len1 - len2);

        if(len1 < len2)
        {
            return collisionPoint(headA, headB, diff);
        }
        else
        {
            return collisionPoint(headB, headA, diff);
        }
        return NULL;
    }
};

//Optimal
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA, *temp2 = headB;
        while(temp1 != temp2)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;

            if(temp1 == temp2)
                return temp1;
            
            if(temp1 == NULL)
                temp1 = headB;
            if(temp2 == NULL)
                temp2 = headA;
        }
        return NULL;
    }
};
