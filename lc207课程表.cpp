class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        to = vector<vector<int>>(numCourses,vector<int>());
        inDeg = vector<int>(numCourses,0);
        for(vector<int>& pre: prerequisites){ //将所有的边存放在出边数组里面
            int ai = pre[0];
            int bi  = pre[1];
            //修ai课程必须先修bi课程，所以是bi->ai的边
            to[bi].push_back(ai);
            inDeg[ai]++; //ai这个点的入度加1
        }
        queue<int> q; //队列辅助BFS;
        //从没有入边的节点开始遍历
        for(int i = 0;i<numCourses;++i){
            if(inDeg[i] == 0) q.push(i);//让入度为0的所有节点入队列
        }
        //拓扑排序：1）从入度为0的节点开始出发，进队列 2）到了一个点，周围的点，需要入度减少1,如果点的入度是0就可以进队列
        vector<int> lessons; //记录修过的课程
        while (!q.empty()){
            int x = q.front();q.pop();
            lessons.push_back(x);
            //修完x课程后，可以考虑x的后继课程了
            for(int y : to[x]){
                inDeg[y]--;//入度减1
                if(inDeg[y] == 0){//入度为0了，就可以修这本课程了
                    q.push(y);
                }
            }
        }
        return lessons.size() == numCourses;
    }
    vector<vector<int>> to; //出边数组存放图
    vector<int> inDeg; //通过所有点的入度
};