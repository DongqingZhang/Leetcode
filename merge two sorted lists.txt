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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1&&!l2) return l1;
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* head, *node, *l1next, *l2next;
        l1next = l1;
        l2next = l2;
        if (l1next->val <= l2next->val){
            head = l1;
            l1next = l1next->next;
        }
        else{
            head = l2;
            l2next = l2next->next;
        }
        node = head;
        while(l1next && l2next){
            if (l1next->val <= l2next->val){
                node->next = l1next;
                l1next = l1next->next;
            }
            else{
                node->next = l2next;
                l2next = l2next->next;
            }
            node = node->next;
        }
        node->next = l1next?l1next:l2next;
        return head;
    }
};