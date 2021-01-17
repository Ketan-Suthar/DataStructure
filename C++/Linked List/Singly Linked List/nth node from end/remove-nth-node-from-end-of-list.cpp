/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(!head) return head;
        if(!head->next)
        {
            if(n==1)
                return nullptr;
            return head;
        }
        ListNode *ahead = head, *behind=head, *temp;
        for(int i=0;i<n;i++)
        {
            if(!ahead)
                return head;
            ahead = ahead->next;
        }
        // cout<<ahead->val;
        if(!ahead)
        {
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }        
        for(;ahead && ahead->next; ahead=ahead->next, behind = behind->next);
        temp = behind->next;
        behind->next = behind->next->next;
        delete temp;
        return head;
    }
};