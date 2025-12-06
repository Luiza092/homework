#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void mirrorTree(TreeNode* root) {
    if (!root) return;

    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    mirrorTree(root->left);
    mirrorTree(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    mirrorTree(root);
    std::cout << "root: " << root->val << '\n';          // 1
    std::cout << "left: " << root->left->val << '\n';    // 3
    std::cout << "right: " << root->right->val << '\n';  // 2
    std::cout << "right->right: " << root->right->right->val << '\n'; // 4
    // Теперь: root->right = 2, root->left = 3, root->right->right = 4

    return 0;
}