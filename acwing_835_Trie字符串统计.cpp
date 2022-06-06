#include <iostream>
using namespace  std;
const int N = 1e6+10; //N是所有字符串的总长度 
char str[N];
//题目说只包含小写字母，那么就只有26条边
//son[][]存储树中每个节点的子节点
int son[N][26],cnt[N],idx;
//cnt存放以当前结尾的单词有多少个;
// 下标是0的节点，即是根节点，又是空节点
/* idx是当前用到的节点的下标;  每一个出现的节点都会有唯一一个编号idx(即指针),不是按照层数编号的，是按照出现的先后顺序;
 */

void insert(char str[]){ //1)插入字符串
    int p = 0; //根节点
    for(int i = 0;str[i];++i){ //字符串结尾是'\0',用来判断是否走向结尾
        //a~z 映射到 0~25
        int u = str[i] -'a';
        if(!son[p][u])  son[p][u] = ++idx;//如果不存在，那么就创建出来
        p = son[p][u];
    }
    cnt[p]++; //最后到了p节点，记录以p结尾的字符串数量加1
}
int query(char str[])   {//2)查询字符串出现多少次
    int p = 0;
    for(int i = 0;str[i];++i){
        int u = str[i] - 'a';
        if(!son[p][u]){//如果不存在，说明没有这个字符，即没有这个字符串
            return 0;
        }
        p = son[p][u];
    }
    return cnt[p]; //返回以p结尾的单词数量
}
int main(){
    int n;
    scanf("%d",&n);
    while (n--){
        char op[2];
        scanf("%s%s",op,str);
        if(op[0]=='I') insert(str);
        else printf("%d\n", query(str));
    }
    return  0;
}