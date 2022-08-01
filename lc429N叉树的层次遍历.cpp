class Solution {
    vector<vector<int>> ans;
public:
   
    vector<vector<int>> levelOrder(Node* root) {
        if(root == nullptr) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size(); //每次都要重新更新size为每一层的宽度
            vector<int> curans;
            for(int i = 0;i<size;++i){
                Node*  cur = q.front();q.pop();
                curans.push_back(cur->val);
                for(Node* tmp : cur->children){
                    //将cur的所有孩子节点全部进队列
                    q.push(tmp);
                }
            }
            ans.push_back(curans);
        }
        return ans;
    }
};