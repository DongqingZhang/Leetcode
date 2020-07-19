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
    bool isPalindrome(ListNode* head) {
        if (!head||!head->next) return true;
        if (!head->next->next){
            if (head->val == head->next->val) return true;
            else return false;
        }
        ListNode *p1 = head, *p2 = head, *pre = head, *p3 = head->next;
        while(p2->next&&p2->next->next){
            p2 = p2->next->next;
            pre = p1;
            p1 = p3;
            p3 = p3->next;
            p1->next = pre;
        }
        head->next = nullptr;
        if (!p2->next) p1 = p1->next;
        while(p1){
            if (p1->val != p3->val) return false;
            p1 = p1->next;
            p3 = p3->next;
        }
        return true;
    }
};