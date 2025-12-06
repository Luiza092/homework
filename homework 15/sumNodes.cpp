#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int sumNodes(TreeNode* root) {
    if (!root) return 0;

    return root->val + sumNodes(root->left) + sumNodes(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    int sum = sumNodes(root);
    std::cout << sum << '\n';  // 10

    return 0;
}