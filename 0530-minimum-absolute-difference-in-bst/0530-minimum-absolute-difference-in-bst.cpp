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
    int getMinimumDifference(TreeNode* root) {
        
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        // if(root == NULL) return {0};
        while(!q.empty()){
            int size = q.size();
            while(size--){
                TreeNode*node = q.front();
                q.pop();
                ans.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
        }
        sort(ans.begin(),ans.end());
        int result  = 1e9;
        for(int i =0;i<ans.size()-1;i++){
            result = min(result,ans[i+1]-ans[i]);
        }
        return result;

    }
};