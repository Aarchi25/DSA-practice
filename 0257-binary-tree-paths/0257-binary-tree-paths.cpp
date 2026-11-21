
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root, "", ans);
        return ans;
    }

    void solve(TreeNode* root, string path, vector<string>& ans) {
        if (root == NULL) return;

        path += to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
            return;
        }

        path += "->";

        solve(root->left, path, ans);
        solve(root->right, path, ans);
    }
};
