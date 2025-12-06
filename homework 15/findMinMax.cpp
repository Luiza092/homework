#include <iostream>
#include <algorithm>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int findMax(TreeNode* root) {
    if (!root) return INT_MIN; // пустое

    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    return std::max({root->val, leftMax, rightMax});
}

int findMin(TreeNode* root) {
    if (!root) return INT_MAX; // пустое

    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);

    return std::min({root->val, leftMin, rightMin});
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);

    std::cout << "Max: " << findMax(root) << '\n'; // 8
    std::cout << "Min: " << findMin(root) << '\n'; // 1

    return 0;
}

