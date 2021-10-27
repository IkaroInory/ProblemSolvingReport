struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<string> BFS(TreeNode* tree) {
    queue<TreeNode*> open;
    vector<string> close;

    open.push(tree);
    while (!open.empty()) {
        TreeNode* temp = open.front();
        open.pop();
        if (temp == nullptr) close.emplace_back("null");
        else {
            close.emplace_back(to_string(temp->val));
            open.push(temp->left);
            open.push(temp->right);
        }
    }
    return close;
}