  void inOrderTraversalRecursion(Node* x){
        if(x == nullptr) return;
        inOrderTraversalRecursion(x->left);
        cout<<x->val<<endl;
        inOrderTraversalRecursion(x->right);
    }
	 void inOrderTraversalIteration(Node* x){//二叉树中序遍历迭代法实现
        if(x == nullptr) return;
        cout<<"inOrderTraversalIteration"<<endl;
        stack<Node* > s;
        Node* cur = x;
        Node* tmp = nullptr;
        //栈不为空或者cur不为空，那么循环继续
        while (!s.empty() || cur){
            if(cur){ //以cur为头节点的树，整条左边进栈(包括cur这个根节点),直到遇到cur的左边为nullptr结束
                s.push(cur);
                cur = cur->left;
            }else {
                cur = s.top(); //从栈中弹出cur,经过上面if判断cur的左边是nullptr,访问cur后，让cur=cur->right;
                s.pop();
                cout<<cur->val<<endl;
                cur = cur->right;
            }
        }
    }