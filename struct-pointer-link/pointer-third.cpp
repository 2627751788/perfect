//3��дһ������ʵ����һ���ַ����в��Ҽ�����������ַ������ҷ�������ַ��ĵ�ַ��
#include <stdio.h>

#define pointer_value 0

#if pointer_value
char *find(char *p, char q, int len);
#else
char *find(char *p, char q);
#endif

int main()
{
    //�����ַ���
    char nums[] = "874ujntq91";
    //������ռ��������ַ��ı���
    int num = 0;
    //�����ַ�
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
        printf("��ƥ���ַ�\r\n");
    }
}

#if pointer_value
//�Ӻ���ʵ�֣�����������ַ�ƥ����ַ����е�λ�ã��������ַ��ĵ�ַ
//���������ַ��ĵ�ַ����ָ�뺯��
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
    return temp;       //����ͬ�ľͷ��ص�ַ
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
 * �ܽῼ��֪ʶ��
 *  ��1���ַ����Ķ����Լ�ע������
 *      ���巽�������֣���
 *      �ַ����飺�����ַ������ʱ��ע�⣬����ĳ���Ҫ��ʵ�ʳ�����+1
 *               ��Ϊ�ַ������һλ��\0���ַ�����������
 *              ���磺
 *                  char nums[] = "222222";
 *                  char nums[] = {"222222"};
 *                  char nums[] = {'1','1','1','1'};
 *              ע�⣬����ʹ�� == ���Ƚ��ַ�����Ҫʹ��strcmp����
 *      �ַ�ָ�룺
 *          char *nums = "123456";  //�÷���Ҳ���Զ������ַ���������
 *   (2) scanf�����޷�Ӧ�������
 *      ���Ͻ�-�ļ�-��ѡ��-����-����run in terminal����
 *   (3) printf�����������
 *      ���VScode���·��и������ʽ��ѡ��GBK����
 *       https://blog.csdn.net/qq_40089560/article/details/105616585?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164587257516780264064327%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=164587257516780264064327&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-2-105616585.pc_search_result_cache&utm_term=vscodeprintf%E4%B8%AD%E6%96%87%E8%A1%8C%E4%B9%B1%E7%A0%81&spm=1018.2226.3001.4187
 *  ��4��VScode���뱨��control reaches end of non-void function [-Wreturn-type]
 *      ԭ���ڱ����ú���ĩβ�Ļ�������return���
 * ***************************************************************/




