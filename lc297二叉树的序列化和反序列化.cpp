  /* 树节点在内存中存放，通过指针串接起来，现在想把这棵树变成文件的形式(那么最好把这棵树转成字符串);
   这个字符串可以代表唯一的树结构，还可以还原出唯一的树来。这就叫二叉树的序列化和反序列化
    * 二叉树可以通过先序、后序或者按层遍历的方式序列化和反序列化，
    * 以下代码全部实现了。
    * 但是，【二叉树无法通过中序遍历的方式实现序列化和反序列化】
    *【 因为不同的两棵树，可能得到同样的中序序列，即便补了空位置也可能一样。】
    * 比如如下两棵树
    *         __2
    *        /
    *       1
    *       和
    *       1__
    *          \
    *           2
    * 补足空位置的中序遍历结果都是{ null, 1, null, 2, null}
    *       null是占位用的，可以确定树的结构，不能忽略。
    * */
//1.先序遍历序列化二叉树和反序列化二叉树：
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //递归的过程中把整棵树序列化的结果填到string中去
        if(root== nullptr) return "#"; //用"#"占位表示null
        string left = serialize(root->left); //递归序列化左树
        string right = serialize(root->right);//递归序列化右树
        string tree = to_string(root->val) + ","+left+","+right; //先序：根左右
        return tree;
    }
  
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;
        queue<string> q = stringToList(data); 
        //反序列化时：先将包含所有节点的大string转成queue<string>
        return preb(q);
    }
    TreeNode* preb(queue<string> &q){
        if(q.size() == 0) return nullptr;
        string ch = q.front();q.pop();
        if(ch == "#"){ //不要忘了这一句，ch可能是#不能转成数字
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(ch));
        //把字符串转成整型然后建出节点，作为此时的头结点
//因为序列化时候是先序：头左右。所以反序列化是先让左树消费队列，再让右树消费队列，最后返回头结点。
        root->left = preb(q);
        root->right = preb(q);
        return root;
    }
    queue<string> stringToList(string & s){
        queue<string> q;
        int len = s.size();
        int i = 0,j = 0;
        while(i<len){
            while(i<len && s[i] == ',') ++i; //跳过','
            int cnt = 0;
            while(i+cnt < len && s[i+cnt]!=',') ++cnt;
            //退出有二种情况：i+cnt >=len 或者 data[i+cnt] ==','
            if(i+cnt<len){//是因为data[i+cnt] == ','退出的
                string tmp = s.substr(i,cnt);
                q.push(tmp);
            }
            i+=cnt;//i跳过这个字符串(data[i+cnt]会来到',',但上面第一行会跳过它)
        }
        return q;
    }
//2.后序遍历序列化和反序列化二叉树：
 
class Codec {
public:
#if 1
    string serialize(TreeNode* root) {
        if(root == nullptr){return "#";}
        stack<TreeNode*> s;
        stack<string> ans;
        s.push(root);
        ans.push(to_string(root->val));
        while(!s.empty()){
            TreeNode* cur = s.top();s.pop();
            if(cur->right){
                ans.push(to_string(cur->right->val));
                s.push(cur->right);
            }else{
                ans.push("#");
            }
            if(cur->left){
                ans.push(to_string(cur->left->val));
                s.push(cur->left);
            }else {
                ans.push("#");
            }
        }
        string tmp;
        while(!ans.empty()){
            tmp+=(ans.top()+",");
            ans.pop();
        }
        return tmp; //队列是:根右左 ->栈出来后是:左右根;得到tmp是后序遍历的字符串
    }
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;
        queue<string> q = stringToList(data); //左右根
        stack<string> s;
        while(!q.empty()){
            s.push(q.front());
            q.pop();
        }
        //左右根 -> 根右左
        return pos(s);
    }
    TreeNode* createNode(string &ch){
        if(ch == "#"){
            return nullptr;
        }else {
            return new TreeNode(stoi(ch));
        }
    }
    TreeNode* pos(stack<string> &s){
        if(s.size() == 0) return nullptr;
        string ch = s.top();s.pop();
        TreeNode* root = createNode(ch);
        stack<TreeNode*> help;
        if(root){
            help.push(root);
        }
        while(!help.empty()){
            TreeNode* node = help.top();help.pop();
            //s弹出的顺序就是:根右左，所以根据这个顺序建立树
            node->right = createNode(s.top());s.pop();
            node->left = createNode(s.top());s.pop();
            if(node->right){
                help.push(node->right);
            } 
            if(node->left){
                help.push(node->left);
            }
        }
        return root;
    }
#endif 
 
    queue<string> stringToList(string & s){
        queue<string> q;
        int len = s.size();
        int i = 0,j = 0;
        while(i<len){
            while(i<len && s[i] == ',') ++i; //跳过','
            int cnt = 0;
            while(i+cnt < len && s[i+cnt]!=',') ++cnt;
            //退出有二种情况：i+cnt >=len 或者 data[i+cnt] ==','
            if(i+cnt<len){//是因为data[i+cnt] == ','退出的
                string tmp = s.substr(i,cnt);
                q.push(tmp);
            }
            i+=cnt;//i跳过这个字符串(data[i+cnt]会来到',',但上面第一行会跳过它)
        }
        return q;
    }
};
//3.层次遍历序列化和反序列化二叉树：
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) { //层次遍历序列化二叉树
        if(root == nullptr) return "#"; //如果是空树，那么直接返回"#"标记
        string ans;
        ans.append(to_string(root->val)+","); //先把根节点序列化
        queue<TreeNode*> q; //辅助队列方便进行层次遍历
        q.push(root); //根节点入队
        while(!q.empty()){
            TreeNode* cur = q.front();q.pop();
            //弹出父节点时候，左边不为空序列化左边，右边不为空就序列化右边
            if(cur->left){//左边不为空就序列化且入队
                ans.append(to_string(cur->left->val)+",");//左孩子序列化
                q.push(cur->left);//左孩子进队
            }else {//左边为空就只序列化，不入队
                ans.append("#,");
            }
            if(cur->right){
                ans.append(to_string(cur->right->val)+",");
                q.push(cur->right);
            }else{
                ans.append("#,");
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return nullptr;
        queue<string> q = stringToList(data);
        return level(q);
    }
    TreeNode* level(queue<string> &q){
        if(q.size() == 0) return nullptr;//这行判断需要加上
        string ch = q.front();q.pop();
        queue<TreeNode*> que;
        TreeNode* head = generetaNode(ch);
        if(head){ //head非空才进队列，如果是空那么跳过while直接返回了
            que.push(head);
        }
        while(!que.empty()){
            TreeNode* cur = que.front();que.pop();
             //当时序列式是让父节点去序列化子节点，所以现在让父节点反序列化子节点。
            cur->left = generetaNode(q.front());q.pop();
            cur->right =generetaNode(q.front());q.pop();
            //当初序列化是非空进队列，所以现在反序列化也是非空进队列
            if(cur->left){
                que.push(cur->left);
            }
            if(cur->right){
                que.push(cur->right);
            }
        }
        return head; 
    }
    TreeNode* generetaNode(string& s){
        if(s == "#"){
            return nullptr;
        }
        return new TreeNode(stoi(s));
        
    }
     queue<string> stringToList(string &s){
        queue<string> q;
        int len = s.size();
        int i = 0,j = 0;
        while(i<len){
            while(i<len && s[i] == ',') ++i; //跳过','
            int cnt = 0;
            while(i+cnt < len && s[i+cnt]!=',') ++cnt;
            //退出有二种情况：i+cnt >=len 或者 data[i+cnt] ==','
            if(i+cnt<len){//是因为data[i+cnt] == ','退出的
                string tmp = s.substr(i,cnt);
                q.push(tmp);
            }
            i+=cnt;//i跳过这个字符串(data[i+cnt]会来到',',但上面第一行会跳过它)
        }
        return q;
    }
};