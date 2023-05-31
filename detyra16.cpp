#include <iostream>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumOfLeftLeaves(TreeNode* root, bool isLeftChild = false) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL && isLeftChild) {
        return root->val;
    }

    int leftSum = sumOfLeftLeaves(root->left, true);
    int rightSum = sumOfLeftLeaves(root->right, false);

    return leftSum + rightSum;
}

int main() {
    // Example 1: [3,9,20,null,null,15,7]
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    cout << "Sum of left leaves (Example 1): " << sumOfLeftLeaves(root1) << endl;

    // Example 2: [1]
    TreeNode* root2 = new TreeNode(1);

    cout << "Sum of left leaves (Example 2): " << sumOfLeftLeaves(root2) << endl;

    return 0;
}
//Time:O(n)
//Space:O(log n)