//�����Ӧ�ã���������-��ѯ���-ɾ���ڵ�-����ڵ㣩
#include <stdio.h>
#include <stdlib.h>

//����
struct Price *Creat_Node();                             //�������
struct Price *Creat_Link(int n);                        //����������Ҫ�õ���㣬����ӱ�ͷ��β��
void Printf_Link(struct Price *head);                   //��ӡ������Ϣ
struct Price *Search_Node(struct Price *head, int id);  //��Ѱ�����еĽ����Ϣ

//����ڵ㣨�ɽṹ��Ԫ����ɣ������������ָ���򣩣�
//����֪ʶ��
/*
1.�ṹ�������
    struct �ṹ������
    {
        Ԫ�أ�
    }��
2.�ṹ���Ƕ��
3.�ṹ��ָ�룺��������һ��ָ�룬ָ��ָ��������ǽṹ��
struct �ṹ������ *������
*/
struct Price
{
    //������
    int ID_Number;
    char Name[20];
    float Cost;

    //ָ����
    struct Price *next;
};

int main()
{
    struct Price *head_new; //��Ŵ���������׵�ַ
    int n;                  //���Ҫ�����Ľ�����
    struct Price *p;        //��Ų�ѯ���Ľ��

    //��������
    printf("�����봴����������:\n");
    scanf("%d",&n);
    head_new = Creat_Link(n);
    //��ӡ������Ϣ
    printf("�½��������ϢΪ:\n");
    Printf_Link(head_new);
    //��ѯ���
    printf("�������ѯ����Ʒ����\n");
    scanf(" %d",&n);
    p = Search_Node(head_new,n);
    if(p != NULL) 
    { 
        printf("ID_Number = %d, Name = %s, Cost = %.2f\n",p->ID_Number,p->Name,p->Cost); 
    } 
    else 
    { 
        printf("��Ҫ��ѯ����Ʒ���벻����\n"); 
    }
}

/*����һ���µ�����(��ͷ--���--��β)
�βΣ������нڵ������
����ֵ�����ش���������׵�ַ����Ϊ��Ҫ����һ����ַ�����Զ���һ��ָ�뺯����ָ�뺯�������������ǽṹ�����ͣ�
�ú���ʱһ��ָ�뺯������������ֵ��һ����ַ
*/
struct Price *Creat_Link(int n)
{
    struct Price *head = NULL;  //��ͷ
    struct Price *pb = NULL;    //����ַ
    struct Price *pf = NULL;    //���浱ǰ���ĵ�ַ�������������ʱ�����������Ϊ�´����Ľ�����һ����㴦��
    int i;  //��ʾ������������

    for(i = 0; i < n; i++)
    {
        //����һ�����
        pb = Creat_Node();  //������һ����㣬��pb��ʾ��һ������ַ
        //�������
        if(i == 0)
        {
            head = pb;  //���ǵ�һ����㣬��˵���ý���ַ���ͷ��ŵ�ַһ��
        }
        else
        {
            pf->next = pb;  //��һ������ָ����ָ��ǰ�½��Ľ��
        }
        pf  = pb;   //���浱ǰ���ĵ�ַ����Ϊ��һ���½�������һ�����
    }
    /* ��ӱ�β */
    if(head != NULL)
    {
        pf->next = NULL;
    }
    return head;
}

/*����һ�����
����ֵ�����������׵�ַ�����ص�ַ����Ҫ�õ�ָ�뺯����
*/
struct Price *Creat_Node()
{
    struct Price *p;    //����һ���ṹ��ָ�������pָ���¿��ٵĽ��ռ�

    /*����һ�����ռ�
        �ǵü�ͷ�ļ�
    */
    p = (struct Price *)malloc(sizeof(struct Price));
    //������д������
    printf("��������Ʒ���롢���ơ��۸�:\n");
    scanf("%d %s %f",&p->ID_Number,&p->Name,&p->Cost);      //���ʽṹ���Ա    1.�ṹ�������.�ṹ���Ա   2.ָ�������->�ṹ���Ա 3.��*ָ���������.�ṹ���Ա
    //ָ����ָ���
    p->next = NULL;
    //���ؽ���׵�ַ
    return p;
}

/*���������Ϣ*/
void Printf_Link(struct Price *head)
{
    while(head != NULL)
    {
         printf("ID_Number = %d, Name = %s, Cost = %.2f\n",head->ID_Number,head->Name,head->Cost);
         head = head->next;
    }
    printf("\n�������\n");
}

/*��ѯ�����Ϣ
��������Ҫ��ѯ�������ַ����Ҫ��ѯ��һ������
��ѯ����������ţ�����Ҫ��ѯ��һ�����
����ֵ�����ز�ѯ���Ľ���ַ
*/
struct Price *Search_Node(struct Price *head, int id)
{
    struct Price *temp  = head;
    //��֤��ѯ�������Ƿ�Ϊ��
    if(temp == NULL)
    {
        return NULL;
    }
    else
    {
        while(temp != NULL)     //ѭ�������е�ÿһ�����
        {
            if(temp->ID_Number == id)
            {
                return temp;
            }
            temp = temp->next; 
        }
    }
    return NULL;
}


