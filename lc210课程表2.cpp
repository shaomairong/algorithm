class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        to = vector<vector<int>>(numCourses,vector<int>());
        inD = vector<int>(numCourses,0);
    
        for(vector<int>& pre : prerequisites){
            int ai = pre[0];
            int bi = pre[1];//修ai课程必须先修bi课程，即bi->ai
            to[bi].push_back(ai);//存储从bi->ai的边
            ++inD[ai];//ai的入度加1
        }
        queue<int> q; //队列辅助进行广度优先遍历，然后进行拓扑排序
        //先让入度为0的所有节点入队列
        for(int i = 0;i<numCourses;++i){
            if(inD[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){//队列非空进行循环bfs
            int cur = q.front();q.pop();
            ans.push_back(cur);
            for(int tmp : to[cur]){
                //不要忘记访问过后要把它指向节点的入度减1
                --inD[tmp];
                if(inD[tmp] == 0){//如果入度为0了，那么可以入队了
                    q.push(tmp);
                }
            }
        }
        if(ans.size() == numCourses) return ans;
        else return {};
    }
    vector<vector<int>> to; //出边矩阵存储图
    vector<int> inD; //存储入度
    vector<int> ans;//存储学习过程
};