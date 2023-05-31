#include <iostream>

using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL) {
        return true;
    }
    if (p == NULL || q == NULL) {
        return false;
    }

    if (p->val != q->val) {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    // Example 1: [1,2,3]
    TreeNode* p1 = new TreeNode(1);
    p1->left = new TreeNode(2);
    p1->right = new TreeNode(3);

    TreeNode* q1 = new TreeNode(1);
    q1->left = new TreeNode(2);
    q1->right = new TreeNode(3);

    cout << "Are the trees same? (Example 1): " << boolalpha << isSameTree(p1, q1) << endl;

    // Example 2: [1,2], [1,null,2]
    TreeNode* p2 = new TreeNode(1);
    p2->left = new TreeNode(2);

    TreeNode* q2 = new TreeNode(1);
    q2->right = new TreeNode(2);

    cout << "Are the trees same? (Example 2): " << boolalpha << isSameTree(p2, q2) << endl;

    return 0;
}
//Time:O(n)
//Space: O(log n)