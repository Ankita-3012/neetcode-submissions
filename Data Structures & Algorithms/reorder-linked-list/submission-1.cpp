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
private:
    ListNode* helper(ListNode* head, ListNode* cur){
        if(!cur) return head;

        head = helper(head, cur->next);
        if(!head) return head;

        ListNode* temp = nullptr;
        if(head == cur || head->next == cur){
            cur->next = nullptr;
        }else{
            temp = head->next;
            head->next = cur;
            cur->next = temp;
        }

        return temp;
    }
public:
    void reorderList(ListNode* head) {
        head = helper(head, head->next);
    }
};
