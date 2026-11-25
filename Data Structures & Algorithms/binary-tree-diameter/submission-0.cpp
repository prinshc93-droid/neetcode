class Solution {
public:
    int ans = 0;

    int height(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Diameter passing through current node
        ans = max(ans, leftHeight + rightHeight);

        // Return height to parent
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;
    }
};