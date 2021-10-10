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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* left = head;
        ListNode* right = head;
        for (int i = 1; i < k;i++) {
            right = right->next;
        }
        while (right->next) {
            left = left->next;
            right = right->next;
        }
        return left;
    }
};