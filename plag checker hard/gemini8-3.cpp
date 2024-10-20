#include <iostream>
#include <algorithm>
#include <limits> // Required for numeric_limits

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxPathSumHelper(TreeNode* root, int& maxSum) {
    // Base case: empty subtree
    if (root == nullptr) {
        return 0;
    }

    // Recursively calculate max path sum from left and right subtrees
    int leftSum = maxPathSumHelper(root->left, maxSum);
    int rightSum = maxPathSumHelper(root->right, maxSum);

    // Calculate the maximum path sum going through the current node
    int maxPathThroughNode = max({root->val, root->val + leftSum, root->val + rightSum, root->val + leftSum + rightSum});

    // Update the global maximum sum
    maxSum = max(maxSum, maxPathThroughNode);

    // Return the maximum path sum starting from the current node (for parent node calculations)
    return max({root->val, root->val + leftSum, root->val + rightSum});
}

int maxPathSum(TreeNode* root) {
    int maxSum = numeric_limits<int>::min(); // Initialize with the smallest possible integer
    maxPathSumHelper(root, maxSum);
    return maxSum;
}


int main() {
    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(-10);
    root->left->right = new TreeNode(4);

    int result = maxPathSum(root);
    cout << "Maximum path sum: " << result << endl; // Output: 10

    //Clean up memory (important to avoid leaks)
    //This requires a more sophisticated tree traversal for larger trees
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}