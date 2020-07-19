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
    ListNode* reverseList(ListNode* head) {
        ListNode *t1 = head;
        if (!t1||!t1->next) return t1;
        ListNode *t2 = t1->next;
        t1->next = nullptr;
        ListNode *t3 = t2->next;
        if (t3 == nullptr){t2->next = t1; return t2;}
        while(t3){
            t2->next = t1;
            t1 = t2;
            t2 = t3;
            t3 = t3->next;
        }
        t2->next = t1;
        return t2;
    }
};