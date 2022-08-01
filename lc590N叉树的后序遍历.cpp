class Solution {
public:
   vector<int> postorder(Node* root) {
        if(root == nullptr) return {};
        vector<int> ans;
        post(root,ans);
        return ans;
    }
    void post(Node* x,vector<int> &ans){
        if(x == nullptr) return ;
        for(Node* cur: x->children){
            post(cur,ans);
        }
        ans.push_back(x->val);
    }
};