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
    ListNode* middleNode(ListNode* head) {
        ListNode* end = head;
        // int end_idx = 1;
        while(end && (end = end->next))
        {
            head = head->next;
            end = end->next;
            // if(end_idx % 2 == 0) head = head->next;
            
        }
        return head;
    }
};