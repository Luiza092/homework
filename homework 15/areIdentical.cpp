#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool areIdentical(TreeNode* r1, TreeNode* r2) {
    if (!r1 && !r2) return true;

    if (!r1 || !r2) return false;

    return (r1->val == r2->val) && areIdentical(r1->left, r2->left)
        && areIdentical(r1->right, r2->right);
}

int main() {
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    bool identical = areIdentical(tree1, tree2);
    std::cout << std::boolalpha << identical << '\n';  // true

    return 0;
}