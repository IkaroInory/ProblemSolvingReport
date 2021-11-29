#include <queue>

using namespace std;

struct cmp {
    bool operator()(ListNode* left, ListNode* right) {
        return left->val > right->val;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        if (l1 != nullptr) q.push(l1);
        if (l2 != nullptr) q.push(l2);

        ListNode* res = new ListNode();
        ListNode* cur = res;
        while (!q.empty()) {
            ListNode* temp = q.top();
            q.pop();
            cur->next = temp;
            if (temp->next != nullptr) q.push(temp->next);
            cur = cur->next;
        }
        return res->next;
    }
};