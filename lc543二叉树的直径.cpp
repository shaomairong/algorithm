class Solution {
public:
    /* 二叉树递归套路实践：
    给定一颗二叉树的头结点，任何二个节点之间存在距离，返回整颗二叉树的最大距离。(这道题如果不用二叉树递归套路做很难)
    注意：这个距离不是高度那种，也可以是 比如x节点的左孩子的左孩子 到 x节点的右孩子 这种距离。一棵树里面距离非常多，请返回最大距离
    */

    /* 目标：[求x为根节点的树中的最大距离。]
列出可能性(难得题目要想可能性跟x有关还是无关？)
跟x无关是：--有可能以x为根节点的整棵树的最大距离是不通过x的;
    1)x的左树的最大距离
    2)x的右树的最大距离
跟x有关是：
    1)x的左树的最大距离
    2)x的右树的最大距离
    3)经过x节点的最大距离：x的左树高度+右树高度+1(当前节点)
所以总结为跟x有关：
    那么需要拿到1,2,3信息，包装为Info。
*/
    struct  Info{
        int maxDistance; //整棵树的最大距离
        int height; //整棵树的高度
        Info(int _m,int _h):maxDistance(_m),height(_h){}
    };
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        return process(root).maxDistance-1;
    }
    Info process(TreeNode* x){ //返回以x为根节点的树的Info
        if(x == nullptr) return Info(0,0);
        //空树Info好设置，空树的最大距离是0，最大高度是0
        Info leftinfo = process(x->left);
        Info rightinfo = process(x->right);
        int height = max(leftinfo.height,rightinfo.height)+1; //以x节点为根的树的最大高度
        int p1 = leftinfo.maxDistance;//1)左树的最大距离
        int p2 = rightinfo.maxDistance;//2)右树的最大距离
        int p3 = leftinfo.height+rightinfo.height+1;//3)最大距离经过x节点
        int maxDistance = max(max(p1,p2),p3);
        //以x为根节点的树的最大距离是p1,p2,p3中最大的(经过x或者不经过x的比较）
        return Info(maxDistance,height);
        //这个返回的是节点数量，题目要求的是长度，因此需要减去1
    }
};
