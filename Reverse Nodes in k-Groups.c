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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || !head|| !head->next) return head;
        ListNode *start = head, *end = head, *pre2;
        ListNode *pre = new ListNode(0);
        pre->next = head;
        ListNode *res = pre;
        ListNode *t1 = start->next, *t2 = start->next->next;
        while(1){
            int cnt = k;
            while(--cnt && end) end = end->next;
            if(!end) break;
            t1 = start->next;
            t2 = t1->next;
            pre2 = start;
            start->next = end->next;
            while(t1 != end){
                t1->next = start;
                start = t1;
                t1 = t2;
                t2 = t2->next;
            }
            t1->next = start;
            pre->next = t1;
            pre = pre2;
            start = t2;
            end = t2;
        }
        return res->next;
    }
};