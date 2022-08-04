class Solution {
public:
#if 0 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //根据先序遍历和中序遍历重构一颗二叉树
        if(preorder.size() == 0 || inorder.size() == 0 ) return nullptr;
        return f(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    //f:从先序遍历pre和中序遍历in重构一颗二叉树，返回头节点
    TreeNode* f(vector<int>& pre,int L1,int R1,vector<int>& in,int L2,int R2){
        if(L1>R1) return nullptr; //不是有效范围
        TreeNode* head = new TreeNode(pre[L1]);//先建出头节点
        if(L1==R1) return head; //这个范围只剩下一个数了，直接生成新节点返回
        /*在先序遍历中用到L1..R1 在中序遍历中用到L2..R2
       显然在先序遍历中L1即为头，所以需要在中序遍历中找到L1头->find。
       然后就可以递归进行
        */
        int find = L2; //从L2位置开始寻找
        for(;in[find]!=pre[L1];++find);
        //for循环退出表示找到[pre第一个元素即头] 在 in中的位置，就可以将in划分
        //in中左树在L2 ~ find-1位置  ，右树在 find+1 ~ R2
        //in中而左树L2 ~ find -1的长度  可以在 pre中定位 L1+1 加上这个长度定位左树
        //为了不算错这里用： L1+  (find -L2 )进行定位，
        // 因为假设in中find前面3个数字，那么在pre中从L1加上3既可以找到这个相同长度的下标
        head->left = f(pre,L1+1,L1+find-L2,in,L2,find-1);
        head->right = f(pre,L1+find-L2+1,R1,in,find+1,R2);
        return head;
    }
#endif 
#if 1
    //优化：在每个范围，每次都要for循环来寻找这个头结点find
    //    可以为中序数组建一张表，每次直接查就行了，就不用遍历了
    //根据先序遍历和中序遍历数组返回一个树
    unordered_map<int,int> m ;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //根据先序遍历和中序遍历重构一颗二叉树
        if(preorder.size() == 0 || inorder.size() == 0 ) return nullptr;
        for(int i = 0;i<inorder.size();++i){
            m[inorder[i]] = i;//从value找index的map
        }
        return f(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    TreeNode* f(vector<int>& pre,int L1,int R1,vector<int>& in,int L2,int R2){
        if(L1>R1) return nullptr; //不是有效范围
        TreeNode* head = new TreeNode(pre[L1]);//先建出头节点
        if(L1==R1) return head; //这个范围只剩下一个数了，直接生成新节点返回
        /*在先序遍历中用到L1..R1 在中序遍历中用到L2..R2
       显然在先序遍历中L1即为头，所以需要在中序遍历中找到L1头->find。
       然后就可以递归进行
        */
        int find = m[pre[L1]]; 
        head->left = f(pre,L1+1,L1+find-L2,in,L2,find-1);
        head->right = f(pre,L1+find-L2+1,R1,in,find+1,R2);
        return head;
    } 

#endif 
};