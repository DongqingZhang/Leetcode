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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        ListNode *slow = dummy, *fast = head;
        slow->next = fast;
        while(fast&&fast->next){
            while(fast&&fast->next&&fast->val==fast->next->val) fast = fast->next;
            if(slow->next!=fast){
                slow->next = fast->next;
                fast = fast->next;
            }
            else{
                slow = slow->next;
                fast = fast->next;
            }
        }
        return dummy->next;
    }
};