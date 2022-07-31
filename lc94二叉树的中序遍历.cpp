class Solution {
    vector<int> ans;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        stack<TreeNode*> s;
        TreeNode* cur = root;
        //栈非空 或者 cur不为空 就继续循环
        while(!s.empty() || cur){
            if(cur){
    //以cur为头节点的树，整条左边进栈(包括cur这个根节点),直到遇到cur的左边为nullptr结束
                s.push(cur);
                cur = cur->left;
            }else {
     //从栈中弹出cur,经过上面if判断cur的左边是nullptr,访问cur后，让cur=cur->right;
                cur = s.top();s.pop();
                ans.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ans;
    }
    vector<int> inorderTraversal1(TreeNode* root) {
        if(root==nullptr) return {};
        in(root);
        return ans;
    }
    void in(TreeNode* x){
        if(x == nullptr) return;
        in(x->left);
        ans.push_back(x->val);
        in(x->right);
    }
};