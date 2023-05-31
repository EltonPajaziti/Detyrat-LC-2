#include <iostream>
#include <algorithm>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return max(leftDepth, rightDepth) + 1;
}

int main() {
    // Example 1: [3,9,20,null,null,15,7]
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);

    cout << "Maximum depth of binary tree (Example 1): " << maxDepth(root1) << endl;

    // Example 2: [1,null,2]
    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);

    cout << "Maximum depth of binary tree (Example 2): " << maxDepth(root2) << endl;

    return 0;
}
//Time:O(n)
//Space:O(log n)