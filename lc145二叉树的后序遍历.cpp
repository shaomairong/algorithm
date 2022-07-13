	void postOrderTraversalRecursion(Node* x){
        if(x == nullptr) return;
        postOrderTraversalRecursion(x->left);
        postOrderTraversalRecursion(x->right);
        cout<<x->val<<endl;
    }
	 /*上面已经实现了非递归先序遍历(根左右),那么只要稍微加工就可以得到非递归后序遍历。
    将非递归先序遍历的压栈顺序改一下，改成先压左子树再压右子树，那么最终的遍历顺序是<根右左>,然后在每次弹出打印时候改成不打印，
    进入另外一个temp栈，当整个操作完成后。从temp栈中弹出元素，那么<根右左>就变成了<左右根>，这就是后序遍历*/
    void postOrderTraversalIteration(Node* x){
        if(x == nullptr) return;
        cout<<"postOrderTraversalIteration"<<endl;
        stack<Node*> s,tmp;//s是类似于辅助先序遍历的栈;tmp是保存遍历元素，最后输出就是后序遍历
        s.push(x);
        while (!s.empty()){
            Node* cur = s.top();
            s.pop();
            tmp.push(cur);
            if(cur->left){
                s.push(cur->left);
            }
            if(cur->right){
                s.push(cur->right);
            }
        }
        while (!tmp.empty()){
            Node* t = tmp.top();
            cout<<t->val<<endl;
            tmp.pop();
        }
    }