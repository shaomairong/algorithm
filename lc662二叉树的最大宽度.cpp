class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        std::queue<std::pair<TreeNode*,unsigned  long long >> q;
        //队列辅助层次遍历：存放pair<节点指针，节点编号>
        q.push({root,1});//根节点入队，编号是1
        unsigned  long long wid = 1;
        while (!q.empty()){
            int sz = q.size(); //获取队列中元素的数量，这就是当前层节点的数量
            unsigned  long long min = q.front().second,max = q.back().second;
            //队列尾节点编号-队列首节点编号+1就是题目要求的宽度
            unsigned  long long w = max - min + 1;
            wid =std::max(wid,w);//跟新宽度
            for(int i = 0;i<sz;++i){
                std::pair<TreeNode*,unsigned  long long > p = q.front();q.pop();
                unsigned long long indx = p.second;
                if(p.first->left) {
                    q.push({p.first->left, 2 * indx});
                }
                if(p.first->right){
                    q.push({p.first->right,2*indx+1});
                }
            }
        }
        return wid;
    }
};