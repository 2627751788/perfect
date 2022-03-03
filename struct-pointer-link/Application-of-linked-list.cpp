//链表的应用（创建链表-查询结点-删除节点-插入节点）
#include <stdio.h>
#include <stdlib.h>

//声明
struct Price *Creat_Node();                             //创建结点
struct Price *Creat_Link(int n);                        //创建链表（需要用到结点，再添加表头表尾）
void Printf_Link(struct Price *head);                   //打印链表信息
struct Price *Search_Node(struct Price *head, int id);  //搜寻链表中的结点信息

//定义节点（由结构体元素组成（包括数据域和指针域））
//考察知识点
/*
1.结构体的声明
    struct 结构体类型
    {
        元素；
    }；
2.结构体的嵌套
3.结构体指针：本质上是一个指针，指针指向的类型是结构体
struct 结构体类型 *变量名
*/
struct Price
{
    //数据域
    int ID_Number;
    char Name[20];
    float Cost;

    //指针域
    struct Price *next;
};

int main()
{
    struct Price *head_new; //存放创建链表的首地址
    int n;                  //存放要创建的结点个数
    struct Price *p;        //存放查询结点的结果

    //创建链表
    printf("请输入创建结点的数量:\n");
    scanf("%d",&n);
    head_new = Creat_Link(n);
    //打印链表信息
    printf("新建链表的信息为:\n");
    Printf_Link(head_new);
    //查询结点
    printf("请输入查询的商品编码\n");
    scanf(" %d",&n);
    p = Search_Node(head_new,n);
    if(p != NULL) 
    { 
        printf("ID_Number = %d, Name = %s, Cost = %.2f\n",p->ID_Number,p->Name,p->Cost); 
    } 
    else 
    { 
        printf("需要查询的商品编码不存在\n"); 
    }
}

/*创建一个新的链表(表头--结点--表尾)
形参：链表中节点的数量
返回值：返回创建链表的首地址（因为需要返回一个地址，所以定义一个指针函数，指针函数的数据类型是结构体类型）
该函数时一个指针函数，函数返回值是一个地址
*/
struct Price *Creat_Link(int n)
{
    struct Price *head = NULL;  //表头
    struct Price *pb = NULL;    //结点地址
    struct Price *pf = NULL;    //保存当前结点的地址（后面新增结点时，串联结点作为新创建的结点的上一个结点处理）
    int i;  //表示创建结点的数量

    for(i = 0; i < n; i++)
    {
        //创建一个结点
        pb = Creat_Node();  //创建第一个结点，且pb表示第一个结点地址
        //串联结点
        if(i == 0)
        {
            head = pb;  //若是第一个结点，则说明该结点地址与表头存放地址一致
        }
        else
        {
            pf->next = pb;  //上一个结点的指针域指向当前新建的结点
        }
        pf  = pb;   //保存当前结点的地址，作为下一次新建结点的上一个结点
    }
    /* 添加表尾 */
    if(head != NULL)
    {
        pf->next = NULL;
    }
    return head;
}

/*创建一个结点
返回值：创建结点的首地址（返回地址，需要用到指针函数）
*/
struct Price *Creat_Node()
{
    struct Price *p;    //定义一个结构体指针变量，p指向新开辟的结点空间

    /*开辟一个结点空间
        记得加头文件
    */
    p = (struct Price *)malloc(sizeof(struct Price));
    //数据域写入数据
    printf("请输入商品编码、名称、价格:\n");
    scanf("%d %s %f",&p->ID_Number,&p->Name,&p->Cost);      //访问结构体成员    1.结构体变量名.结构体成员   2.指针变量名->结构体成员 3.（*指针变量名）.结构体成员
    //指针域指向空
    p->next = NULL;
    //返回结点首地址
    return p;
}

/*输出链表信息*/
void Printf_Link(struct Price *head)
{
    while(head != NULL)
    {
         printf("ID_Number = %d, Name = %s, Cost = %.2f\n",head->ID_Number,head->Name,head->Cost);
         head = head->next;
    }
    printf("\n输出结束\n");
}

/*查询结点信息
参数：需要查询的链表地址：需要查询那一个链表
查询条件（结点编号）：需要查询那一个结点
返回值：返回查询到的结点地址
*/
struct Price *Search_Node(struct Price *head, int id)
{
    struct Price *temp  = head;
    //验证查询的链表是否为空
    if(temp == NULL)
    {
        return NULL;
    }
    else
    {
        while(temp != NULL)     //循环链表中的每一个结点
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


