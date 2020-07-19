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
    ListNode* partition(ListNode* head, int x) {
        ListNode* p1 = new ListNode(0), *p2 = new ListNode(0);
        ListNode* res = p1, *intm = p2;
        while(head){
            if (head->val<x)
                p1 = p1->next = head;
            else
                p2 = p2->next = head;
            head = head->next;
        }
        p2->next = nullptr;
        p1->next = intm->next;
        return res->next;
    }
};