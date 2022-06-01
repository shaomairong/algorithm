#include <vector>
#include <iostream>
#include <algorithm>
using namespace  std;
const int N = 300010; //数据范围是10w，但是离散化后是30w个[n+2m]
//因为需要离散化的是坐标，题目中涉及坐标的操作有三个[x、l和r]，每个规模最大10w，所以就是30w
int n,m;
int a[N],s[N];//a是离散化后的值，s是前缀和数组
vector<int> alls; //vector存放要离散的下标
using PII = std::pair<int,int>; //每次操作都是二个数，所以用pair存放
vector<PII>  add,query; //存放插入操作和查询操作的vector
int find(int x){ //求x离散化后的结果
    //alls里面存放的是原始数组的下标
    int l = 0,r = alls.size()-1;
    //要找的是大于等于x中最小的数
    while (l<r){
        int mid = l+r>>1;
        if(alls[mid] >= x){
            r=mid;
        }else {
            l = mid+1;
        }
    } //退出时l==r
    return r+1; //这里是把x映射到从1开始的自然数，所以加1; (映射到从0开始就不需要加1）
    //因为后面用到前缀和，前缀和从1开始存储方便使用
}
//双指针实现unique (这里实现只是为了练习双指针，实际做算法可以直接调库函数unique)
//不同元素满足的性质:1)他是第一个2)它跟前一个元素不一样
std::vector<int>::iterator  myunique(std::vector<int> & a){ 
    int j = 0;
    for(int i = 0;i<a.size();++i){ //第一个指针i指向要遍历的数
        if(!i || a[i]!= a[i-1]){//把满足性质数拿出来放到数组里面去
            a[j++] = a[i]; //第二个指针j表示当前存到了第几个数(保证j<=i)
        }
    } //a[0]~a[j-1]就是所有不同的数了
    return a.begin()+j; //返回尾后迭代器
}
int main(){
    cin>>n>>m;
    for(int i = 0;i<n;++i){
        int x,c;
        cin>>x>>c;
        add.push_back({x,c}); //插入操作，下标x的位置加上c
        //要把下标x离散化，所以把x加入到待离散化的vector里面
        alls.push_back(x);
    }
    for(int i = 0;i<m;++i){
        int l,r;
        cin>>l>>r;
        query.push_back({l,r});
        //区间l和r也是要离散化的（即跟下标有关的都要离散化)
        alls.push_back(l);
        alls.push_back(r);
    }
    //此时把所有用到的数组下标放到了alls里面,然后需要去重
    std::sort(alls.begin(),alls.end()); //排序
    alls.erase(myunique(alls),alls.end()); //去重
    //unique函数是去重，返回去重之后的尾迭代器it,即it到alls.end()之间就是重复元素，删除它们即可
    for(std::pair<int,int> item : add){ //处理插入操作
        int x = find(item.first); //通过find由原始下标iterm.first计算出离散化后的下标x
        a[x]+=item.second; //在a数组中x位置加上值
    }
    for(int i =1;i<=alls.size();++i  ){ //预处理前缀和
        s[i] = s[i-1]+a[i];
    }
    for(std::pair<int,int> item : query){ //处理询问
        int l = find(item.first),r = find(item.second);
        //通过原始下标计算出离散化后的下标，然后用离散化后的下标去前缀和数组求解
        cout<<s[r]-s[l-1]<<endl;
    }
    return  0;
}