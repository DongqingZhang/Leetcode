/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        ListNode *tmp1 = head, *headnew = new ListNode(0);
        ListNode *i = headnew;
        i->next = head;
        while(tmp1){
            if (tmp1->val!=9) i=tmp1;
            tmp1=tmp1->next;
        }
        i->val++;
        while(i=i->next) i->val = 0;
        if (headnew->val) return headnew;
        return head;
    }
};