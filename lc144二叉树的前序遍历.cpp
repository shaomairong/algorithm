 void preOrderTraversalRecursion(Node* x){
        if(x == nullptr) return;
        cout<<x->val<<endl;
        preOrderTraversalRecursion(x->left);
        preOrderTraversalRecursion(x->right);
    }
	 void preOrderTraversalIteration(Node* x){//先序遍历二叉树迭代法:
        if(x == nullptr ) return;
        cout<<"preOrderTraversalIteration"<<endl;
        stack<Node*> s;//用栈模拟递归
        s.push(x);//先把头节点压栈
        while (!s.empty()){ //栈非空就继续循环
            Node* cur = s.top(); //栈中弹出节点
            s.pop();
            cout<<cur->val<<endl;
            //cur有右节点就压入栈，有左节点就压入栈(因为栈是后进先出，所以按照根左右的遍历，应该先压右子树节点)
            if(cur->right){
                s.push(cur->right);
            }
            if(cur->left){
                s.push(cur->left);
            }
        }
    }