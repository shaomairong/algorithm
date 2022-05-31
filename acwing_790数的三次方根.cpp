#include <iostream>
using namespace std;
int main(){
    std::ios::sync_with_stdio(false);
    double n ;
    cin>>n;
    double l = -10000,r = 10000;
    while (r-l > 1e-8){ //保留6位小数，就是1e-8
        double  mid = (r+l)/2;
        if(mid * mid * mid  >=n   )  r =mid;
        else l = mid;
		//因为是浮点数二分，所以不需要整数二分那样l=mid+1
    }
    printf("%lf",l); //浮点数的double输出用%lf
    return 0;
}
