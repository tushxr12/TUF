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
private:
    bool isPali(vector<int> &v)
    {
        int left = 0, right = v.size() - 1;
        while(left < right)
        {
            if(v[left] != v[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        while(temp != NULL)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        if(isPali(v))
            return true;
        return false;
    }
};
