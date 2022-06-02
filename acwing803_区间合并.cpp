#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

using PII = std::pair<int,int>;
const int N = 100010; //N个区间，n最大是10000
int n ;
vector<PII> segs;
// merge函数将所有存在交集的区间合并
void merge(vector<PII>& segs){
    vector<PII> res;
    //区间开始和结束节点存放pair中，对vector排序
    sort(segs.begin(),segs.end()); //pair排序先根据first再根据second
    //题目数字边界是-10^9
    int st = -2e9 , ed = -2e9; //输入数据最小和最大的边界;当前维护的开始和结束区间[st,ed]
    for(auto seg : segs){//从前往后扫描所有的线段
        if(ed < seg.first){//1)发现是不同区间，保存答案 （维护的区间结尾ed在遍历的frist的前面)
            if(st!= -2e9){ 
              //因为第一次st和ed是边界，if判断是初始默认区间就跳过，不是第一次就记录答案
                res.push_back({st,ed}); 
            }
            st = seg.first;//更新边界
            ed =seg.second;
        }else { //ed>=seg.first说明重合了，那就更新ed
         //2)区间由重合部分 ，那么合并区间 （当前维护区间ed和当前区间的最大值)
            ed = max(ed,seg.second);
        }
    }
    if(st!= -2e9){
        //循环结束后要把最后一个区间加到答案里面去（if判断是防止输入数组没有任何区间)
        res.push_back({st,ed});
    }
    segs = res;
}
int main(){
    cin>>n;
    for(int i = 0;i<n;++i){
        int l,r;
        cin>>l>>r;
        segs.push_back({l,r});
    }
    merge(segs);
    cout<<segs.size()<<endl;
    return  0;
}