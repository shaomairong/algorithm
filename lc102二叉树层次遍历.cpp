 vector<vector<int> > levelOrder(Node* root) {
        // write code here
        vector<vector<int> > v;
        if(root == nullptr) return v;
        Node* cur = root;
        queue<Node*> q;
        q.push(cur);
        while(!q.empty()){
            int size = q.size(); //先获取当前层的节点数
            vector<int> ans;
            for(int i = 0;i<size;++i){ //将当前层的节点遍历，同时将它的孩子节点加入队列
                cur = q.front();
                q.pop();
                ans.push_back(cur->val);
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
            v.push_back(ans); //二叉树层次遍历正序收集节点;如果要倒序收集，那么每次在首部位置插入即可
        }
        return v;
    }