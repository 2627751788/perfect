//2、编写一个子函数，函数功能是将两个数组中的对应位的值相加，然后保存到第 3 个数组中。
#include <stdio.h>

//#define method

//方法1：
#ifdef method
void summery(int *p,int *q,int len);
#else
//方法2
int *summery(int *p,int *q,int len);
#endif

int main()
{
	//定义两个数组
	int num1[6] = {9,4,9,0,4,7};
	int num2[6] = {4,6,2,8,1,7};

	//将两个数组传到子函数中去实现
    #ifdef method
	//方法1
	summery(num1, num2, sizeof(num1)/sizeof(int));
    #else
	//方法2
	int *num4 = summery(num1, num2, sizeof(num1)/sizeof(int));
	for(int i = 0;i < sizeof(num1)/sizeof(int);i++)
	{
		printf("num4 = %d\r\n",num4[i]);
	}
    #endif
}

#ifdef method
//定义子函数，实现两个数组中对应值相加存储到第三个数组中，并返回第三个数组的值
//方法1
void summery(int *p,int *q,int len)
{
	int num3[6] = {0};
	//定义数组三
	for(int temp = 0; temp < len; temp++)
	{
		//num3[temp] = p[temp] + q[temp];
		num3[temp] = *(p + temp) + *(q + temp);
		printf("num3 = %d temp = %d\r\n",num3[temp], temp);
	}
}
#else
//也可使用指针函数实现（指针函数可返回一个地址，本质是一个函数，数据类型是指针类型）
//方法2
int *summery(int *p,int *q,int len)
{
	static int num3[6] = {0};	//若此处定义为局部变量，则无法返回该变量（局部变量的作用域只在summery函数内部，函数运行完就释放了）
	//定义数组三
	for(int temp = 0; temp < len; temp++)
	{
		//num3[temp] = p[temp] + q[temp];
		num3[temp] = *(p + temp) + *(q + temp);
		//printf("num3 = %d temp = %d\r\n",num3[temp], temp);
	}
	return num3;
}
#endif

/**************************************************************
 * 总结考察知识点：
 *  （1）指针函数的使用（指针函数：本质是一个函数，函数类型是指针，函数的返回值是一个地址（指针））
 *      常用于返回一个数组或指针的地址
 *  （2）#ifdefine 宏定义的使用
 *      #define 宏          //通用标识
 *      #ifdef  宏
 *      #else
 *      #endif
 * 
 *      #define 宏 值       //常量定义
 *      #if 宏
 *      #elif
 *      #else
 *      #endif
 *  
 *      #ifndef
 *      #define
 * 
***************************************************************/