/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        if(!head->next) return nullptr;
        int tot = 0;
        ListNode* cur = head;
        while(cur){
            tot++;
            cur = cur->next;
        }

        int k = tot-n;
        if(k==0) return head->next;

        cur = head;
        ListNode* prev = nullptr;
        int i=0;
        while(cur){
            if(i==k){
                prev->next = cur->next;
                break;
            }
            prev = cur;
            cur = cur->next;
            i++;
        }

        return head;
    }
};
