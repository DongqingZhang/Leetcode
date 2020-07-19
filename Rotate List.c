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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *tmp1 = head, *tmp2 = head,* tmp3 = head;
        if (head == nullptr) return head;
        int count = 0;
        while (tmp3){
            tmp3 = tmp3->next;
            count++;
        }
        k %= count;
        for (int i = 0;i<k;i++){
            tmp2 = tmp2->next;
        }
        while(tmp2->next){
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        tmp2->next = head;
        ListNode* res = tmp1->next;
        tmp1->next = nullptr;
        return res;
    }
};