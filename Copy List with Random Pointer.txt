/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return nullptr;
        RandomListNode *iter1 = head, *next;
        while(iter1){
            next = iter1->next;
            iter1->next = new RandomListNode(iter1->label);
            iter1->next->next = next;
            iter1 = next;
        }
        iter1 = head;
        while(iter1){
            next = iter1->next;
            if(iter1->random) next->random = iter1->random->next;
            iter1 = next->next;
        }
        iter1 = head;
        RandomListNode *headNew = head->next;
        while(iter1){
            next = iter1->next;
            iter1->next = next->next;
            iter1 = iter1->next;
            if(iter1){
                next->next = iter1->next;
                next = iter1;
            }
        }
        return headNew;
    }
};