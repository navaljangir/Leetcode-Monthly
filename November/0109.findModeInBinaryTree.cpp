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
int maxi = INT_MIN;
   void solve(TreeNode* root , unordered_map<int,int>&mp){
        if(root==NULL){
            return;
        }
        mp[root->val]++;
        maxi = max(maxi , mp[root->val]);
        solve(root->left, mp);
        solve(root->right ,mp);
    }
    vector<int> findMode(TreeNode* root) {
        TreeNode* temp = root;
        unordered_map<int,int> mp;
        vector<int> ans;
        solve(temp, mp);
        for(auto i : mp){
            if(i.second==maxi){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
