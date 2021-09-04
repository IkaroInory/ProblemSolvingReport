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
        int len = 0;
        ListNode* p = head;
        while (p) {
            len++;
            p = p->next;
        }

        int location = len / 2;
        while (location--) {
            head = head->next;
        }
        return head;
    }
};