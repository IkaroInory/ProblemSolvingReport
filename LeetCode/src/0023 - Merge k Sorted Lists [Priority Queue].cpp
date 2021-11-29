#include <queue>

using namespace std;

struct cmp {
    bool operator()(ListNode* left, ListNode* right) {
        return left->val > right->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, cmp>q;
        for (int i = 0; i < size; i++)
            if (lists[i] != nullptr) q.push(lists[i]);

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