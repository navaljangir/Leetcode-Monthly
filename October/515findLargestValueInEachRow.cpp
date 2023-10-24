//level Order traversal
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        if(root==NULL){
            return {};
        }
        q.push(root);
        q.push(NULL);
        vector<int> v; 
        int maxi = INT_MIN;
        while(!q.empty()){
            if(q.front()!=NULL)
            maxi = max(maxi ,q.front()->val);
            if(q.front()==NULL){
                v.push_back(maxi);
                maxi = INT_MIN;
                q.pop();
                if(!q.empty()){
                    q.push(NULL);
                }
                continue;
            }
            if(q.front()->left){
                q.push(q.front()->left);
            }
            if(q.front()->right){
                q.push(q.front()->right);
            }
            q.pop();
        }
        return v;
    }
};

