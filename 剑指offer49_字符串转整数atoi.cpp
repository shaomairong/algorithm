namespace  algorithm{
	/*首先想一想需要处理的情况: int atoi(const char *str)
	1) 如果str是nullptr，应该返回0；如果str=" ",也返回0;如果str="0"，也返回0;
		那么如何区分非法输入得到的0还是正确是"0"呢？通过全局变量g_status
	2) 如果只输入"+"和"-"处理：返回0，g_status设置Invalid表示非法输入
	3) 数字字符串前面有正负号需要先提取出来，用bool minus记录
	4) 处理溢出情况:数字字符串很大或者很小，超过了int的最大值0x7FFFFFFF和最小值0x80000000,
		用long long ans 记录每次算到的结果，如果ans超过了限制就设置为0，同时g_status设置为Invalid
		注意:ans和int的最小值比较时候要用:ans < (signed int )0x80000000,要强转为有符号数
	5） 如果不是"0"~"9"之间的字符串，那就是非法字符，直接ans给0，然后g_status设置为Invalid
	*/
	
    enum Status{ Valid = 0,Invalid};
    int g_status = Valid;
    long long process(const char * s,bool minus){
        long long maxInt = 0x7FFFFFFF; //int能表示的最大值
        long long minInt = 0x80000000; //int能表示的最小值
        long long ans = 0; //用long long类型变量存储计算结果，后面要和int最大最小值判断
        while (*s != '\0'){ //没到结尾就继续循环
            if(*s -'0' >=0 && *s-'0' <=9){//有效数字字符
                ans = ans * 10 + *s - '0';
                if( (!minus && ans > maxInt) ||//是正数 且 超过了int正数的最大值
                        (minus && ans < (signed int)minInt )){//是负数 且 超过了int负数的最小值
                    g_status = Invalid;
                    ans = 0;
                    break;
                }
                s++; //指针移动计算判断字符
            }else {//非法字符，直接ans给0，然后status设置为Invalid
                ans = 0;
                g_status = Invalid;
                break;
            }
        }
        if(*s == '\0') g_status = Valid;
		//遍历结束没有退出，表示是有效的数字字符串，设置全局标记
        return  minus? 0 - ans: ans; 
		//如果minus为1，那么返回负数;minus为0返回正数
    }
    int atoi(const char * str){
        g_status = Invalid;//先假设是非法输入
        long long  num = 0;
        bool minus = 0; 
		//比较前面有没有负号，minus为0表示前面是正号或者没有符号，minus为1表示前面有负号
        //str == nullptr 直接返回0，通过g_status为Invalid判断是非法输入
        //str !=nullptr 但 *str =='\0'也返回0，通过g_status为Invalid判断是非法输入
        if(str != nullptr && *str != '\0'){
            //判断首字符是不是正负号
            if(*str == '+'){
                ++str;
                minus = 0;
            }else if(*str == '-'){
                ++str;
                minus = 1;
            }
            if(*str !='\0'){
                num = process(str,minus);//开始转换
            }
        }
        return   (int)num; //long long类型转换为int 
    }
}
void Test(char* string)
{
    int result = algorithm::atoi(string);
    if(result == 0 && algorithm::g_status == algorithm::Invalid)
        printf("the input %s is invalid.\n", string);
    else
        printf("number for %s is: %d.\n", string, result);
}
using  namespace  algorithm;
int main()
{
    Test(NULL);

    Test("");

    Test("123");

    Test("+123");

    Test("-123");

    Test("1a33");

    Test("+0");

    Test("-0");

    //有效的最大正整数, 0x7FFFFFFF
    Test("+2147483647");

    Test("-2147483647");

    Test("+2147483648");

    //有效的最小负整数, 0x80000000
    Test("-2147483648");

    Test("+2147483649");

    Test("-2147483649");

    Test("+");

    Test("-");

    return 0;
}