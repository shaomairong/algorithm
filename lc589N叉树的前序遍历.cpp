class Solution {
    vector<int> ans;
public:
    vector<int> preorder(Node* root) {
        if(root== nullptr) return {};
        stack<Node*> s;
        s.push(root);
        while(!s.empty()){
            Node* cur = s.top();s.pop();
            ans.push_back(cur->val);
            //注意这里循环遍历所有孩子节点，因为栈是先进后出，所以需要从后往前遍历孩子节点
            for(int i = cur->children.size()-1;i>=0;--i){
                s.push(cur->children[i]);
            }
        }
        return ans;
    }
    #if 0 
    vector<int> preorder1(Node* root) {
        if(root == nullptr){
            return {};
        }
        pre(root);
        return ans;
    }
    void pre(Node* x){
        if(x == nullptr) return ;
        ans.push_back(x->val);
        for(Node* cur : x->children){
            pre(cur);
        }
    }
    #endif 
};