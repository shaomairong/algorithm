class Solution {
public:
    struct Info{
        bool findA;//当前子树找到A节点了吗
        bool findB;//当前子树找到B节点了吗
        TreeNode* ans;//当前子树发现A和B的最低公共祖先了吗？没有发现ans就是nullptr
        Info(bool a,bool b):findA(a),findB(b),ans(nullptr){}
        Info(bool a,bool b,TreeNode* p):findA(a),findB(b),ans(p){}
    };
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || p == nullptr || q == nullptr) return nullptr;
        return process(root,p,q).ans;
    }
    Info process(TreeNode* x,TreeNode* a,TreeNode* b){
        if(x == nullptr) return Info(false, false, nullptr);
        //如果x为空，那么以x为根节点的树没有发现a和b，也没找到汇聚节点(返回nullptr)
        Info leftInfo = process(x->left,a,b);
        Info rightInfo = process(x->right,a,b);
        //加工以x为根节点的树的Info
        bool findA = ( x == a || leftInfo.findA || rightInfo.findA);
        //当前子树找到a了吗？x为a或者左子树找到a了或者右子树找到a了
        bool findB = (x == b || leftInfo.findB|| rightInfo.findB);
        //当前子树找到b了吗？x为b或者左子树找到b了或者右子树找到b了
        TreeNode* ans = nullptr; //当前子树是否发现a和b的公共祖先了？先设置为nullptr，后面发现了再更改即可
        if(leftInfo.ans){
            ans = leftInfo.ans;
        }else if(rightInfo.ans){
            ans  = rightInfo.ans;
        }else {//左右子树都没有发现a和b的最低公共祖先，[但如果x节点为a或者b，另一个节点在另外一颗子树上面，那么当前节点就是最低公共祖先]
            if(findA && findB){
                ans = x;
            }
        }
        return Info (findA,findB,ans);
    }

#if 0
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || p == nullptr || q == nullptr   ) return nullptr;
        //建立一个从子节点到父节点的map
        unordered_map<TreeNode*,TreeNode*> m;
        m[root] = nullptr; //根节点的父节点是nullptr
        fillParentMap(root,m);
        TreeNode* cur= p;
        unordered_set<TreeNode*>   s;
        s.insert(cur);
        while (m.find(cur)!=m.end()){//将从p到根节点的所有节点全部入set
            cur = m[cur];
            s.insert(cur);
        }
        cur = q;
        while (s.find(cur) == s.end()){//从q开始在set中找，找到了就是最近公告祖先，没找到q根据map变成他的父节点
            cur = m[cur];
        }
        return cur;
    }
    void fillParentMap(TreeNode* x,unordered_map<TreeNode*,TreeNode*> &m){
        if(x->left){
            m[x->left] = x;
            fillParentMap(x->left,m);
        }
        if(x->right){
            m[x->right] = x;
            fillParentMap(x->right,m);
        }
    }
#endif
};