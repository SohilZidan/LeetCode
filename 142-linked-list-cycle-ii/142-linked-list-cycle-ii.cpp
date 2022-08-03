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
    // ListNode *detectCycle(ListNode *head) {
    //     unordered_set<ListNode*> visited;
    //     ListNode* curr = head;
    //     int idx = 0;
    //     while(curr)
    //     {
    //         auto search = visited.find(curr);
    //         if(search != visited.end()) return *search;
    //         visited.insert(curr);// = idx++;
    //         curr = curr->next;
    //     }
    //     return nullptr;
    // }
    

    ListNode *detectCycle(ListNode *head) {
        ListNode *slowptr = head,
                  *fastptr = head;
        bool looped = false;
        while(fastptr != nullptr
             && fastptr->next != nullptr)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
            if(slowptr == fastptr)
            {
                looped = true;
                break;
            }
        }
        
        // if no loop exists
        if(!looped)
            return nullptr;
        
        // reset slowptr to head
        // and traverse again
        slowptr = head;
        while(slowptr != fastptr)
        {
            slowptr = slowptr->next;
            fastptr = fastptr->next;
        }
        return slowptr;
    }
};