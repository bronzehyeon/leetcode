/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        int d = depth(root);
        vector<vector<int>> v(d);
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});

        while(!q.empty()){
            int idx = q.front().first;
            TreeNode* cur = q.front().second;
            q.pop();
            if(cur == nullptr){
                continue;
            }
            v[idx].push_back(cur->val);

            q.push({idx + 1, cur->left});
            q.push({idx + 1, cur->right});
        }
        return v;
    }

    int depth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return max(depth(root->left),depth(root->right)) + 1;
    }
};