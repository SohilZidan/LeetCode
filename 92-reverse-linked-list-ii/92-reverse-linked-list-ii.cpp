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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *prev, *last, *curr;
        prev = new ListNode(-501, head);
        last = head;
        curr = head->next;
        int curr_pos = 2;

        while(curr && (curr_pos - 1) < left)
        {
            prev = prev->next;
            curr = curr->next;
            last = last->next;
            curr_pos++;
            
        }
        while(curr && curr_pos <= right)
        {
            last->next = curr->next; // 1
            curr->next = prev->next; // 2
            prev->next = curr;       // 3
            curr = last->next;       // 4
            curr_pos++;
        }
        return prev->val == -501? prev->next: head;
    }
};