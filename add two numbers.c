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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int resDig;
        int carry = 0;
        ListNode* res = new ListNode(0);
        ListNode* resFinal = res;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        while(p1||p2){
            if (p1&&p2){
                res->next = new ListNode(0);
                res = res->next;
                resDig = p1->val + p2->val+carry;
                if (resDig>9)
                    carry = 1;
                else carry = 0;
                res->val = resDig%10;
            }
            else if(p1){
                res->next = new ListNode(0);
                res = res->next;
                resDig = p1->val+carry;
                if (resDig>9)
                    carry = 1;
                else carry = 0;
                res->val = resDig%10;
            }
            else if(p2){
                res->next = new ListNode(0);
                res = res->next;
                resDig = p2->val+carry;
                if (resDig>9)
                    carry = 1;
                else carry = 0;
                res->val = resDig%10;
            }
            if (p1)
                p1 = p1->next;
            if (p2)
                p2 = p2->next;
        }
        if (carry){
            res->next = new ListNode(0);
            res = res->next;
            res->val = carry;
        }
        res->next = NULL;
        return resFinal->next;
    }
};