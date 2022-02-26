//3、写一个函数实现在一个字符串中查找键盘上输入的字符，并且返回这个字符的地址。
#include <stdio.h>

#define pointer_value 0

#if pointer_value
char *find(char *p, char q, int len);
#else
char *find(char *p, char q);
#endif

int main()
{
    //定义字符串
    char nums[] = "874ujntq91";
    //定义接收键盘输入字符的变量
    int num = 0;
    //输入字符
    scanf("%c", &num);

    #if pointer_value
    char *find_num = find(nums, num, sizeof(nums)/sizeof(char));
    #else
    char *find_num = find(nums, num);
    #endif
    if(find_num != NULL)
    {
        printf("find_num = %p %c nums = %d\r\n",find_num, *find_num, sizeof(nums)/sizeof(char));
    }
    else
    {
        printf("无匹配字符\r\n");
    }
}

#if pointer_value
//子函数实现：查找输入的字符匹配的字符串中的位置，并返回字符的地址
//看到返回字符的地址，用指针函数
char *find(char *p, char q, int len)
{
    static char *temp = 0;
    for(int i = 0;i < len; i++)
    {
        if(q == p[i])
        {
            temp = &(p[i]);
            
        }
        else if(i >= len)
        {
            return 0;
        }
    }
    return temp;       //有相同的就返回地址
}
#else
char *find(char *p, char q)
{
    char *temp = 0;
    while(*p != '\0')
    {
        if(*p == q)
        {
            temp = p;
            break;
        }
        p++;
    }
    return temp;
}
#endif
/*****************************************************************
 * 总结考察知识点
 *  （1）字符串的定义以及注意事项
 *      定义方法（两种）：
 *      字符数组：定义字符数组的时候注意，数组的长度要在实际长度上+1
 *               因为字符串最后一位是\0（字符串结束符）
 *              例如：
 *                  char nums[] = "222222";
 *                  char nums[] = {"222222"};
 *                  char nums[] = {'1','1','1','1'};
 *              注意，不能使用 == 来比较字符串，要使用strcmp函数
 *      字符指针：
 *          char *nums = "123456";  //该方法也会自动加上字符串结束符
 *   (2) scanf输入无反应解决方法
 *      左上角-文件-首选项-设置-勾上run in terminal即可
 *   (3) printf函数输出乱码
 *      点击VScode右下方有个编码格式，选择GBK编码
 *       https://blog.csdn.net/qq_40089560/article/details/105616585?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164587257516780264064327%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=164587257516780264064327&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-105616585.pc_search_result_cache&utm_term=vscodeprintf%E4%B8%AD%E6%96%87%E8%A1%8C%E4%B9%B1%E7%A0%81&spm=1018.2226.3001.4187
 *  （4）VScode编译报错control reaches end of non-void function [-Wreturn-type]
 *      原因：在被调用函数末尾的花括号无return语句
 * ***************************************************************/




