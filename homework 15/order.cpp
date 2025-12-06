#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Прямой обход: Корень – Левый – Правый
void preorder(TreeNode* root) {
    if (!root) return;
    std::cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Симметричный обход: Левый – Корень – Правый
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    std::cout << root->val << " ";
    inorder(root->right);
}

// Обратный обход: Левый – Правый – Корень
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->val << " ";
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    preorder(root);   // Вывод: 1 2 3
    std::cout << '\n';

    inorder(root);    // Вывод: 2 1 3
    std::cout << '\n';

    postorder(root);  // Вывод: 2 3 1
    std::cout << '\n';

    return 0;
}