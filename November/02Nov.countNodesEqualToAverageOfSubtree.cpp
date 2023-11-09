//Bruteforce o(n^2)
class Solution {
public:
    int countNodes(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int ans = 1+ countNodes(root->right)+countNodes(root->left);
        return ans;
    }
    int solve(TreeNode* root , int&count){
        if(root==NULL){
            return 0;
        }
        int rootVal = root->val;
        // count++;
        int leftVal = solve(root->left ,count);
        int rightVal = solve(root->right, count);
        int getCount = countNodes(root);
        if(llround((rootVal+leftVal +rightVal)/getCount)==rootVal){
            count++;
        }
        return rootVal+rightVal + leftVal;
    }
    int averageOfSubtree(TreeNode* root) {
        int count =0 ; 
        int sum = solve(root , count);
        return count;
    }
};



//optimised o(n)

class Solution {
public:
    pair<int,int> solve(TreeNode* root , int&count){
        if(root==NULL){
            return {0,0};
        }
        pair<int,int> p = {root->val , 1};
        pair<int,int> leftVal = solve(root->left, count);
        pair<int,int> rightVal = solve(root->right , count);
        if(llround(p.first + leftVal.first+rightVal.first)/(p.second+leftVal.second+rightVal.second)==root->val){
            count++;
        }
        return {p.first+leftVal.first +rightVal.first , p.second+leftVal.second+ rightVal.second};
    }
    int averageOfSubtree(TreeNode* root) {
        int count =0 ;
        pair<int,int> p = solve(root , count);
        return count;
    }
};
