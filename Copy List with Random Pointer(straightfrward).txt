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
        RandomListNode *iter1 = head;
        unordered_map<RandomListNode*, int> map1;
        int cnt = 0;
        while(iter1){
            map1[iter1] = cnt++;
            iter1 = iter1->next;
        }
        map1[nullptr] = -1;
        unordered_map<int, int> mapcnt;
        iter1 = head;
        cnt = 0;
        while(iter1){
            mapcnt[cnt++] = map1[iter1->random];
            iter1 = iter1->next;
        }
        RandomListNode *iter2 = new RandomListNode(0);
        RandomListNode *headNew = iter2;
        iter1 = head;
        cnt = 0;
        unordered_map<int, RandomListNode*> map2;
        while(iter1){
            iter2->label = iter1->label;
            map2[cnt++] = iter2;
            iter1 = iter1->next;
            if(iter1) iter2->next = new RandomListNode(0);
            iter2 = iter2->next;
        }
        iter2 = headNew;
        cnt = 0;
        while(iter2){
            if(mapcnt[cnt] == -1) iter2->random = nullptr;
            else iter2->random = map2[mapcnt[cnt]];
            cnt++;
            iter2 = iter2->next;
        }
        return headNew;
    }
};