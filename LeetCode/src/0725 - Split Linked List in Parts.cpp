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
    ListNode* cut(ListNode* temp) {
        ListNode* res = temp->next;
        temp->next = nullptr;
        return res;
    }
    ListNode* cut(ListNode* temp, int len) {
        ListNode* res = temp;
        for (int i = 0; i < len; i++) res = res->next;
        for (int i = 0; i < len - 1; i++) temp = temp->next;
        temp->next = nullptr;
        return res;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            len++;
        }

        int groupLen = len / k;
        vector<ListNode*> res;
        if (groupLen == 0) {
            for (int i = 0; i < len; i++) {
                res.emplace_back(head);
                head = cut(head);
            }
            for (int i = 0; i < k - len; i++) {
                res.emplace_back(nullptr);
            }
        }

        int longerCount = len - groupLen * k;
        for (int i = 0; i < k; i++) {
            res.emplace_back(head);
            if (longerCount-- > 0) {
                head = cut(head, groupLen + 1);
            }
            else {
                head = cut(head, groupLen);
            }
        }
        return res;
    }
};