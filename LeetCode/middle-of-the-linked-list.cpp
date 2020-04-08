// Problem URL: https://leetcode.com/problems/middle-of-the-linked-list/
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
    ListNode* middleNode(ListNode* head) {
        ListNode* ptr = head,*dbptr = head;
        while (true) {
            if (dbptr->next == NULL) break;
            if (dbptr->next->next == NULL) {
                ptr = ptr->next;
                break;
            }
            dbptr = dbptr->next->next;
            ptr = ptr->next;
        }
        return ptr;
    }
};