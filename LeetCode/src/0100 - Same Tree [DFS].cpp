struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<string> DFS(TreeNode* tree) {
        stack<TreeNode*> open;
        vector<string> close;

        open.push(tree);
        while (!open.empty()) {
            TreeNode* temp = open.top();
            open.pop();
            if (temp == nullptr) close.emplace_back("null");
            else {
                close.emplace_back(to_string(temp->val));
                open.push(temp->right);
                open.push(temp->left);
            }
        }
        return close;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<string> tree1 = DFS(p);
        vector<string> tree2 = DFS(q);
        int len1 = tree1.size();
        int len2 = tree2.size();

        if (len1 != len2) return false;
        for (int i = 0; i < len1; i++) {
            if (tree1[i] != tree2[i]) return false;
        }
        return true;
    }
};