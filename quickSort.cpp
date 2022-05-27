#include <iostream>
#include <algorithm> //swap
#include <utility> //pair
#include <stack>
#include <memory> //shared_ptr
using namespace std;

namespace algorithm{
    //
	std::pair<int,int> partition(int *arr,int L,int R){
        //返回等于区开始位置和结束位置的下标[start,end]构成的数组
        if(L>R){
            return std::make_pair(-1,-1);//不是有效范围
        }
        if(L==R){//只有一个元素
            return std::make_pair(L,L);
        }
        int lessR = L-1; //小于区有边界在L的前一个位置
        int moreL = R; //大于区左边界是R,因为N-1位置元素是划分之，即最后一个位置元素
        int index = L;
        //对0到N-2范围上的数组元素遍历进行划分,N-1位置元素是划分值,循环结束后将它放到中间
        while (index< moreL){//当前位置不能跟大于区左边界撞上
            if(arr[index] < arr[R]){//1)如果当前位置元素小于划分值，当前位置元素和小于区下一个位置元素交换，小于区右扩，当前位置跳下一个
                swap(arr[index++],arr[++lessR]);
            }else if(arr[index] > arr[R]){//2)当前位置元素大于划分值，当前位置元素和大于区前一个位置元素交换，大于区左扩，当前位置不变
                swap(arr[index],arr[--moreL]);
            }else {//3)当前位置元素等于划分值，当前位置跳下一个
                ++index;
            }
        }
        //循环结束:将划分值(数组末尾元素)和大于区开始位置元素交换
        //因为数组最后一个位置元素是划分值，应该放到等于区里面，这里选择大于区的开头
        swap(arr[moreL],arr[R]);
        return std::make_pair(lessR+1,moreL); //lessR+1是等于区开始位置，moreL经过上面交换后现在等于区结束位置
    }
    void quickProcess1(int *arr,int L,int R){
        if(L>=R){
            return;
        }
//        int i = L+(R-L)/2; 1)选择中间点
//        swap(arr[i],arr[R]);
        int i = rand()%(R-L+1) +L;  //随机出L~R之间的随机数
        swap(arr[i],arr[R]);
        std::pair<int,int> p = partition(arr,L,R);
        quickProcess1(arr,L,p.first-1);
        quickProcess1(arr,p.second+1,R);
    }
    void quickSort1(int *arr,int N){
        if(arr == nullptr || N<2){
            return;
        }
        quickProcess1(arr,0,N-1);
    }
	
	class Job{
    public:
        int l;
        int r ;
        Job(int left,int right):l(left),r(right){}
    };
    void quickSort2(int *arr,int N){
        if(arr == nullptr || N<2){
            return;
        }
        int i = rand()%N ;
        swap(arr[i],arr[N-1]);
        std::pair<int,int> pair = partition(arr,0,N-1);
        std::stack<std::shared_ptr<Job>> stack;
        stack.push(std::make_shared<Job>(0,pair.first-1));
        stack.push(std::make_shared<Job>(pair.second+1,N-1));
        while (!stack.empty()){
            std::shared_ptr<Job> pjob = stack.top();
            stack.pop();
            if(pjob->l < pjob->r){
                 i = rand()%(pjob->r - pjob->l +1) +pjob->l;
                swap(arr[i],arr[pjob->r]    );
                pair = partition(arr,pjob->l,pjob->r);
                stack.push(std::make_shared<Job>(pjob->l,pair.first-1       ));
                stack.push(std::make_shared<Job>(pair.second+1,pjob->r  ));
            }
        }
    }
	
	
}
// const int N = 1e6+10;
// int q[N]; 使用全局数组
int main(){
    int n;
    
    srand(time(0)); //初始化随机数种子
    scanf("%d",&n);
    int * q = new int [n]; //使用动态分配内存的数组
    for(int i = 0;i<n;++i){
        scanf("%d",&q[i]);
    }
    // algorithm::quickSort2(q,n); //递归版本
    algorithm::quickSort1(q,n); //非递归版本
    for(int i = 0;i<n;++i){
        printf("%d ",q[i]);
    }
    
    
}
    