#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int countNodesAtDepth(TreeNode* root, int k) {
    if (!root) return 0;

    if (k == 1) return 1;

    return countNodesAtDepth(root->left, k-1) + countNodesAtDepth(root->right, k-1);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int count = countNodesAtDepth(root, 3);
    std::cout << count << '\n';  // 2

    return 0;
}