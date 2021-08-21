struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = l1;
        int carry = 0;

        while (l1 || l2) {
            if (!l1->next && l2->next) l1->next = new ListNode();
            if (!l2->next && l1->next) l2->next = new ListNode();

            l1->val += carry;
            if (l1->val + l2->val > 9) {
                carry = (l1->val + l2->val) / 10;
                l1->val = l1->val + l2->val - 10;
            }
            else {
                carry = 0;
                l1->val = l1->val + l2->val;
            }
            if (!l1->next && !l2->next && carry) {
                l1->next = new ListNode(carry);
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        
        return ans;
    }
};