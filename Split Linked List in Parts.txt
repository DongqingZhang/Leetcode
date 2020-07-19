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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res(k,nullptr);
        if(!root) return res;
        int cnt = 1;
        ListNode *iter = root, *pre = new ListNode(0);
        pre->next = root;
        while(iter = iter->next) cnt++;
        int small = cnt/k;
        int rem = cnt-small*k;
        iter = root;
        for(int i = 0;i<k;i++,rem--){
            res[i] = iter;
            pre->next = nullptr;
            for(int j = 0;j<small+(rem>0);j++){
                pre = iter;
                iter = iter->next;
            }
        }
        return res;
    }
};