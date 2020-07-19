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
    ListNode* swapPairs(ListNode* head) {
        if (!head||!head->next) return head;
        ListNode* tmp1 = new ListNode(0);
        tmp1->next = head;
        ListNode* tmp2 = head;
        ListNode* res = head->next;
        while(tmp2&&tmp2->next){
            tmp1->next = tmp2->next;
            tmp1 = tmp1->next;
            tmp2->next = tmp1->next;
            tmp1->next = tmp2;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        return res;
    }
};