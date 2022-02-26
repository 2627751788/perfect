//C语言之指针练习题
/**********************************************************************************
1、编写一个子函数，函数实现的功能是将两个数组中的所有值相加，然返回最终的结果。
2、编写一个子函数，函数功能是将两个数组中的对应位的值相加，然后保存到第 3 个数组中。
3、写一个函数实现在一个字符串中查找键盘上输入的字符，并且返回这个字符的地址。
4、写一个函数对数组内的内容进行排序。提示：冒泡法排序。
5、写一个函数实现把输入的两个字符串连接成一个字符串，并且返回连接好的字符串的首地址。
6、编写一个子函数实现在键盘上输入两个字符串，比较输入的字符串是否一样。
7、编写一个子函数实现在键盘上输入一个字符串，检测输入的字符串是否为回文。
***********************************************************************************/

//1.编写一个子函数，函数实现的功能是将两个数组中的所有值相加，然返回最终的结果。
/*#include <stdio.h>

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
}*/

//2、编写一个子函数，函数功能是将两个数组中的对应位的值相加，然后保存到第 3 个数组中。
#include <stdio.h>
//方法1：
//void summery(int *p,int *q,int len);
//方法2
int *summery(int *p,int *q,int len);
int main()
{
	//定义两个数组
	int num1[6] = {9,4,9,0,4,7};
	int num2[6] = {4,6,2,8,1,7};

	//将两个数组传到子函数中去实现
	//方法1
	//summery(num1, num2, sizeof(num1)/sizeof(int));
	//方法2
	int *num4 = summery(num1, num2, sizeof(num1)/sizeof(int));
	for(int i = 0;i < sizeof(num1)/sizeof(int);i++)
	{
		printf("num4 = %d\r\n",num4[i]);
	}
}

//定义子函数，实现两个数组中对应值相加存储到第三个数组中，并返回第三个数组的值
//方法1
/*void summery(int *p,int *q,int len)
{
	int num3[6] = {0};
	//定义数组三
	for(int temp = 0; temp < len; temp++)
	{
		//num3[temp] = p[temp] + q[temp];
		num3[temp] = *(p + temp) + *(q + temp);
		printf("num3 = %d temp = %d\r\n",num3[temp], temp);
	}
}*/
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



