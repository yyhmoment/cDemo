#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
typedef int DataType;   /*定义一个DataType为int类型*/
typedef struct linknode /*定义一个单链表结构体*/

// int LengthList(LinkList *head);

{
  DataType data;         /*定义结点的数据域*/
  struct linknode *next; /*定义结点的指针域*/
} LinkList;

/*定义一个初始化链表的函数*/
LinkList *InitList()
{
  LinkList *head;                              /*头结点*/
  head = (LinkList *)malloc(sizeof(LinkList)); /*动态分配一个结点空间*/
  head->next = NULL;
  return head; /*头结点L指针域为空，表示空链表，（由这提供了一张链表的位置）*/
}

/*1-1头插法建立链表函数*/
void CreatListH(LinkList *head, int n)
{
  LinkList *s;
  int i;
  printf("请输入%d个整数", n);
  for (i = 0; i < n; i++)
  {
    s = (LinkList *)malloc(sizeof(LinkList)); /*malloc分配所需的内存空间，并返回一个指向它的指针，*/
    scanf("%d", &s->data);                    /*其中（Linklist *）就是要malloc返回指向这种类型的一个指针*/
    s->next = head->next;
    head->next = s;
  }
  printf("头插法建立单链表成功！");
}

/*1-2尾插法建立链表函数*/
void CreateListL(LinkList *head, int n)
{
  LinkList *s, *last; /*定义一个s指针，用于动态生成新结点；last为尾指针，便于操作*/
  int i;
  last = head; /*last始终指向尾结点，开始时指向头结点（头尾指针在一个结点，可以表示此表为空）*/
  printf("请输入%d个整数：", n);
  for (i = 0; i < n; i++)
  {
    s = (LinkList *)malloc(sizeof(LinkList));
    scanf("%d", &s->data);
    s->next = NULL;
    last->next = s;
    last = s;
  }
  printf("尾插法建立单链表成功！");
}

void InsList(LinkList *head, int i, DataType x)
{ /*按位置插入元素函数*/
  int j = 0;
  LinkList *p, *s;
  p = head;
  while (p->next != NULL && j < i - 1) /*定位插入点*/
  {
    p = p->next;
    j++;
  }
  if (p != NULL) /*P不为空则将新结点插到p后*/
  {
    s = (LinkList *)malloc(sizeof(LinkList)); /*生成新结点*/
    s->data = x;                              /*将数据x放入新结点的数据域*/
    s->next = p->next;                        /*将新结点s的指针域与p结点后面元素相连*/
    p->next = s;                              /*将p与新结点s链接*/
    printf("插入元素成功！");
  }
  else
    printf("插入元素失败！");
}

/*3.按位置删除链表中元素*/
void DelList(LinkList *head, int i)
{
  DataType x;
  int j = 0;
  LinkList *p, *s;
  p = head;
  while (p->next != NULL && j < i - 1) /*i-1找到的是被删元素的前驱结点*/
  {
    p = p->next;
    j++;
  }
  if (p->next != NULL && j == i - 1)
  {
    s = p->next; /*存储被删除结点的地址*/
    x = s->data; /*存储被删结点的data值*/
    p->next = s->next;
    free(s);
    printf("删除第%d位上的元素%d成功！", i, x);
  }
  else
  {
    printf("删除结点位置错误，删除失败！");
  }
}

/*6.求链表长度的函数*/
int LengthList(LinkList *head)
{
  LinkList *p;    /*定义一个p指针，便于操作*/
  p = head->next; /*把头指针指向头结点的next赋值给p*/
  int j = 0;      /*计数*/
  while (p != NULL)
  {
    p = p->next; /*当p的next域不为空，就把p当前所指结点的next域（即下一个结点的位置）赋值给p，即实现p的移位了*/
    j++;
  }
  return j;
}

/*4.按位置查找*/
void SearchList(LinkList *head, int i)
{
  LinkList *p;
  int j = 0;
  p = head;
  if (i > LengthList(head)) /*通过用户输入的位置数字（i）和调用LengthList函数比较做个判断，防止客户输入超过表长的位置数字*/
  {
    int len = LengthList(head);
    printf("位置错误，链表中没有该位置！\n");
    printf("tips：当前链表长度为%d,请输入在此长度内的数字位置\n", len);
  }
  while (p->next != NULL && j < i) /*p所指的next域不为空和计数器j小于输入的序号*/
  {
    p = p->next;
    p++;
  }
  if (j == i) /*判断于给定的序号是否相等*/
  {
    printf("在第%d位上的元素值为%d！", i, p->data);
  }
}

/*5.按元素值查找元素位置*/
void Locate(LinkList *head, DataType x)
{ /*x为输入的要被查找位置的元素值，用DateType指定类型，为了方便维护修改*/
  LinkList *p;
  p = head->next;
  int j = 1;                        /*计数器*/
  while (p != NULL && p->data != x) /*查找及定位*/
  {
    p = p->next; /*没找到就p指针按条件一值移动，且计数器j++*/
    j++;
  }
  if (p != NULL)
  {
    printf("在表的第%d为找到值为%d的结点!", j, x);
  }
  else
  {
    printf("未找到值为%d的结点！", x);
  }
}

/*7.输出当前的链表*/
void DispList(LinkList *head)
{
  LinkList *p;
  p = head->next;
  while (p != NULL)
  {
    printf("%5d", p->data);
    p = p->next;
  }
}

/*显示菜单子函数*/
void MenuLine()
{
  printf("\n线性表子系统");
  printf("\n===========================================");
  printf("\n|           1-建立                        |");
  printf("\n|           2-插入                        |");
  printf("\n|           3-删除                        |");
  printf("\n|           4-按位置查找                   |");
  printf("\n|           5-按元素值查找                 |");
  printf("\n|           6-求表长                       |");
  printf("\n|           7-输出当前链表                 |");
  printf("\n|           0-返回                         |");
  printf("\n============================================");
  printf("\n请输入菜单号（0~6）：");
}

int main()
{
  LinkList *head;
  DataType x;
  int i, n;
  char ch1, ch2, a;
  ch1 = 'y';
  head = InitList();
  while (ch1 == 'y' || ch1 == 'Y')
  {
    MenuLine();
    scanf("%c", &ch2);
    getchar(); /*防止数据类型不一致*/
    switch (ch2)
    {
    case '1': /*用尾插法创建链表*/
      // head = InitList();
      printf("请输入要建立数据表的长度：");
      scanf("%d", &n);
      CreateListL(head, n); /*这里使用尾插法来建立链表，如果要使用头插法，就改为CreatListH(L)*/
      printf("建立后的线性表为：\n");
      DispList(head);
      break;
    case '2':                                 /*按位置插入元素*/
      if (head->next == NULL || head == NULL) /*判定当带头结点的指针域或不带头结点的指针域为空时，*/
      {                                       /*即表示此时链表为空，此时就提示用户先建表再进行此操作*/
        printf("请建链表后再进行插入操作!\n");
        continue; /*跳过此次操作*/
      }
      else
      {
        printf("请输入要插入的元素位置：");
        scanf("%d", &i);
        getchar();
        printf("请输入要插入的元素值：");
        scanf("%d", &x);
        InsList(head, i, x);
        printf("插入元素%d后的线性表为：\n", x);
        DispList(head);
      }
      break;
    case '3': /*删除元素*/
      if (head->next == NULL || head == NULL)
      {
        printf("请建链表后再进行删除操作!\n");
        continue;
      }
      else
      {
        printf("请输入要删除的元素位置：");
        scanf("%d", &i);
        DelList(head, i);
        printf("删除第%d位的元素后的线性表为：\n");
        DispList(head);
      }
      break;
    case '4': /*按位置查找元素*/
      if (head->next == NULL || head == NULL)
      {
        printf("请建链表后再进行按位置查找元素操作!\n");
        continue;
      }
      else
      {
        printf("请输入查找的元素位置（大于等于1的整数）：");
        scanf("%d", &i);
        SearchList(head, i);
      }
      break;
    case '5': /*按值查找元素位置*/
      if (head->next == NULL || head == NULL)
      {
        printf("请建链表后再进行按值查找操作!\n");
        continue;
      }
      else
      {
        printf("请输入查找的整数：");
        scanf("%d", &x);
        Locate(head, x);
      }
      break;
    case '6': /*链表长度*/
      printf("该线性表的长度为%d！", LengthList(head));
      break;
    case '7':
      if (head->next == NULL || head == NULL)
      {
        printf("当前为空表，请建表后再进行此操作！");
        continue;
      }
      else
      {
        printf("输出链表：");
        DispList(head);
      }
      break;
    case '0': /*返回操作*/
      ch1 = 'n';
      break;
    default:
      printf("输入有误，请输入0-9进行选择！");
    }
    if (ch2 != '0')
    {
      printf("\n按回车键继续，按任意键返回主菜单！\n");
      a = getchar();
      if (a != '\xA')
      {
        getchar();
        ch1 = 'n'; /*控制while循环*/
      }
    }
  }

  return 0;
}