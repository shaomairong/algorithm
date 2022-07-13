想要翻转二叉树，只需要把每个节点的左右孩子交换一下就可以了;
二叉树的遍历顺序(先序、中序、后序、层次遍历，选择那个呢？)
遍历的过程中去翻转每一个节点的左右孩子就可以达到整体翻转的效果。
注意只要把每一个节点的左右孩子翻转一下，就可以达到整体翻转的效果
这道题目使用前序遍历和后序遍历都可以，唯独中序遍历不行，
因为中序遍历会把某些节点的左右孩子翻转了两次！建议拿纸画一画，就理解了
那么层序遍历可以不可以呢？依然可以的！
只要把每一个节点的左右孩子翻转一下的遍历方式都是可以的！
递归法翻转二叉树：递归先序遍历翻转二叉树
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)  return nullptr;
        //递归出口: 如果root为nullptr，直接返回nullptr
        swap(root->left,root->right);
        //交换root的左右节点
        invertTree(root->left); //递归去左子树进行翻转
        invertTree(root->right);//递归去右子树进行翻转
        return root; 
    }
};
递归算法三要素：
1「确定递归函数的参数和返回值：」确定哪些参数是递归的过程中需要处理的，那么就在递归函数里加上这个参数， 并且还要明确每次递归的返回值是什么进而确定递归函数的返回类型。
2「确定终止条件：」写完了递归算法,  运行的时候，经常会遇到栈溢出的错误，就是没写终止条件或者终止条件写的不对，操作系统也是用一个栈的结构来保存每一层递归的信息，如果递归没有终止，操作系统的内存栈必然就会溢出。
3「确定单层递归的逻辑：」确定每一层递归需要处理的信息。在这里也就会重复调用自己来实现递归的过程。
先序遍历迭代法翻转二叉树:
TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        stack<TreeNode*> s; //先序遍历迭代需要栈辅助
        TreeNode* cur = root;
        s.push(cur);
        while(!s.empty()){
            cur = s.top();
            s.pop();
            swap(cur->left,cur->right); //弹出节点，交换它的左右节点
            if(cur->right){
                s.push(cur->right);
            }
            if(cur->left){
                s.push(cur->left);
            }
        }
        return root;
    }
层次遍历翻转二叉树：
  TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr ) return root;
        queue<TreeNode*> q;
        TreeNode* cur  = root;
        q.push(cur);
        while(!q.empty()){
            int size = q.size();
            for(int i= 0;i<size;++i){ //遍历这一层的节点
                cur = q.front();
                q.pop();
                swap(cur->left,cur->right); //从队列弹出节点，交换它的左右节点
                if(cur->left){
                    q.push(cur->left);
                }
                if(cur->right){
                    q.push(cur->right);
                }
            }
        }
        return root;
    }

	