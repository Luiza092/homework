#include <iostream>
#include <vector>
#include <limits>
#include  <stdexcept>

template <typename T>
class BinarySearchTree {

  struct TreeNode {

    T data;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    explicit TreeNode(T val) : data(val) {}
    void print() {

      if (left) left->print();
      std::cout << data << ' ';
      if (right) right->print();
    }
    void insert(const T& val) {
      if (val < data) {
        if (!left) {
          left = new TreeNode(val);
        }
        else {
          left->insert(val);
        }
      }
      else if (val > data) {
        if (!right) {
          right = new TreeNode(val);
        }
        else {
          right->insert(val);
        }
      }
    }

    bool search(const T& val) {

      if (val > data) {
        if (!right) {
          return false;
        }
        return right->search(val);
      }

      else if (val < data) {
        if (!left) {
          return false;
        }
        return left->search(val);
      }

      else {
        return true;
      }

    }

    bool isValidBST(T min, T max) {
      if (data <= min || data >= max) return false;

      bool leftValid = !left || left->isValidBST(min, data);
      bool rightValid = !right || right->isValidBST(data, max);
      return leftValid &&  rightValid;
    }

  };

  TreeNode* root = nullptr;

  TreeNode* deleteNode(TreeNode* node, const T& val) {
    if (!node) return nullptr;

    if (val < node->data) {
      node->left = deleteNode(node->left, val);
    }
    else if (val > node->data) {
      node->right = deleteNode(node->right, val);
    }
    else {
      if (!node->left) {
        TreeNode* tmp = node->right;
        delete node;
        return tmp;
      }
      else if (!node->right) {
        TreeNode* tmp = node->left;
        delete node;
        return tmp;
      }
      else {
        TreeNode* tmp = node->right;
        while (tmp->left) {
          tmp = tmp->left;
        }
        node->data  = tmp->data;
        node->right = deleteNode(node->right, tmp->data);
      }
    }
    return node;
  }

  T kthSmallest(TreeNode* node, int& k) {
    if (!node) throw std::runtime_error("k is too large");

    if (node->left) {
      T val = kthSmallest(node->left, k);
      if (k == 0) return val;
    }

    k--;
    if (k == 0) return node->data;

    if (node->right) return kthSmallest(node->right, k);
    return node->data;
  }

  TreeNode* sortedArrayToBSTHelper(const std::vector<T>& arr, int l, int r) {
    if (l > r) return nullptr;

    int mid = l + (r - l) / 2;
    auto node = new TreeNode(arr[mid]);
    node->left = sortedArrayToBSTHelper(arr, l, mid - 1);
    node->right = sortedArrayToBSTHelper(arr, mid + 1, r);
    return node;
  }

  int countInRange(TreeNode* node, const T& low, const T& high) {
    if (!node) return false;
    if (node->data < low) return countInRange(node->right, low, high);
    if (node->data > high) return countInRange(node->left, low, high);
    return 1 + countInRange(node->left, low, high) +
      countInRange(node->right, low, high);
  }

  bool hasPathSum(TreeNode* node, T sum) {
    if (!node) return false;
    if (!node->left && !node->right) return node->data == sum;
    return hasPathSum(node->left, sum - node->data) ||
      hasPathSum(node->right, sum - node->data);
  }

public:
  void printInorder() {
    if (!root) {
      std::cout << "Empty Tree\n";
      return;
    }
    root->print();
  }
  void insert(const T & val) {
    if (!root) {
      root = new TreeNode(val);
    }
    else {
      root->insert(val);
    }
  }

  bool search(const T& val) {
    if (!root) {
      return false;
    }

    return root->search(val);
  }

  void deleteValue(const T& val) {
    root = deleteNode(root, val);
  }

  T findMinBST() {
    TreeNode* tmp = root;
    if(!tmp)
      throw std::runtime_error("error");
    while (tmp->left) {
      tmp = tmp->left;
    }
    return tmp->data;

  }

  T findMaxBST() {
    TreeNode* tmp = root;
    if (!tmp)
      throw std::runtime_error("error");
    while (tmp->right) {
      tmp = tmp->right;
    }
    return tmp->data;
  }

  bool isValidBST() {
    if (!root) return true;
    return root->isValidBST(std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
  }

  T kthSmallest(int k) {
    if (!root) throw std::runtime_error("Empty tree");
    return kthSmallest(root, k);
  }

  void buildFromSortedArray(const std::vector<T>& arr) {
    root = sortedArrayToBSTHelper(arr, 0, arr.size() - 1);
  }

  int countInRange(const T& low, const T& high) {
    return countInRange(root, low, high);
  }

  bool hasPathSum(T sum) {
    return hasPathSum(root, sum);
  }
};

int main() {

  std::vector<int> nums = { 1,2,4,66,788,9, 123,0,54642,-567576,-548,755 };

  BinarySearchTree<int> t;
  for (int i : nums) {
    t.insert(i);
  }
  t.printInorder();

  std::cout << "\n" << t.search(3) << '\n';

  std::cout << "Min: " << t.findMinBST() << "\n" << "Max: " << t.findMaxBST() << std::endl;

  std::cout << t.isValidBST() << "\n";

  std::cout << "Smallest: " << t.kthSmallest(3) << "\n";

  t.deleteValue(7);
  t.printInorder();

  std::cout << "\n";

  std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  t.buildFromSortedArray(arr);
  t.printInorder();

  std::cout << "\n";

  std::cout << "count in [3, 6]: " << t.countInRange(3, 6) << "\n";

  std::cout << "Has path sum 7: " << t.hasPathSum(7) << "\n";
  std::cout << "Has path sum 10: " << t.hasPathSum(10)  << "\n";
  std::cout << std::endl;

  return 0;
}