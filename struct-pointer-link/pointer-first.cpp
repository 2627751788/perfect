//1.编写一个子函数，函数实现的功能是将两个数组中的所有值相加，然返回最终的结果。
#include <stdio.h>

int summery(int* p, int* q, int len);	//声明子函数
int main()
{	
	//定义两个数组
	int num1[6] = {9,4,9,0,4,7};
	int num2[6] = {4,6,2,8,1,7};

	//将定义的数组传入子函数中计算
	int value = summery(num1,num2,sizeof(num1)/sizeof(int));
	//sizeof（num1）：表示所有数据的字节
	//sizeof（int）:表示一个数据的字节

	//输出打印结果
	printf("value = %d\r\n", value);

}

//实现两个数组中的所有值相加，并返回结果
int summery(int* p, int* q, int len)
{
	int sum = 0;

	for (int temp = 0; temp < len; temp++)
	{
		sum += *(p + temp);
		sum += *(q + temp);
	}
	return sum;
}

/***************************
 * 总结考察知识点：
 * 1.指针的应用1（当函数需要传递数组时，用指针来做形参实现）
 * 2.计算数组的长度
 * 3.指向数组的指针的使用方法
 *      （1）指向数组的指针当做指针使用时*（p+x），需要用*去取内容
 *      （2）指向数组的指针当做数组使用时p[x]，不需要使用*去取内容
 *      （3）指针的运算只能用++ -- + - 
 *          优先级：++-- > * > +- 
****************************/