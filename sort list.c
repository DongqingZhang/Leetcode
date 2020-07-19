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
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
    ListNode* mergeSort(ListNode* head){
        if (!head||!head->next) return head;
        ListNode *walker, *runner;
        walker = head;
        runner = head;
        while(runner->next&&runner->next->next){
            walker = walker->next;
            runner = runner->next->next;
        }
        ListNode* head1 = head;
        ListNode* head2 = walker->next;
        walker->next = nullptr;
        head1 = mergeSort(head1);
        head2 = mergeSort(head2);
        return mySort(head1, head2);
    }
    ListNode* mySort(ListNode *head1, ListNode *head2){
        ListNode* helper;
        if (!head1&&!head2) return head1;
        if (!head1) return head2;
        if (!head2) return head1;
        ListNode* head, *node, *l1next, *l2next;
        l1next = head1;
        l2next = head2;
        if (l1next->val<=l2next->val){
            head = l1next;
            l1next = l1next->next;
        }
        else{
            head = l2next;
            l2next = l2next->next;
        }
        node = head;
        while(l1next && l2next){
            if (l1next->val<=l2next->val){
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